#include <string>
#include <vector>
#include <algorithm>
#include <seqan/score.h>


#include <Rcpp.h>

using namespace seqan;
using namespace Rcpp;


// [[Rcpp::depends(BH)]]
// [[Rcpp::depends(RSeqAn)]]
// [[Rcpp::plugins(cpp14)]]

//' @title seq_dist_with_gappos
//' @name seq_dist_with_gappos
//' @author Julian Spagnuolo
//' @description 
//'
//' @param 
//' @export
// [[Rcpp::export]]
std::vector<int> seq_dist_with_gappos(std::string cdrx, std::string cdry, int gappos, bool trim)
{
  int ntrim;
  int ctrim;
  int r;
  int dist = 0;
  int count = 0;
  
  std::vector<int> result;
  
  r = cdrx.size() - gappos;
  
  Rcout << "start_dist_with_gappos" << std::endl;
  
  if(trim == true)
  {
    ntrim = 3;
    ctrim = 2;
  }else{
    ntrim = 0;
    ctrim = 0;
  }
  
  if(ntrim < gappos)
  {
    for(int i = ntrim; i < gappos; i++)
    {
      dist += 4 - score(Blosum62(), cdrx[i], cdry[i]);
      count += 1;
    }
    Rcout << "seq_dist_gappos_1" << "\t" << gappos << "\t" << ntrim << "\t" << ctrim << "\t" << r << "\t" << dist << std::endl;
  }
  if(ctrim < r)
  {
    for(int i = ctrim; i < r; i++)
    {
      dist += score(Blosum62(), cdrx[-1-i], cdry[-1-i]);
      count += 1;
    }
  }
  
  result[0] = dist;
  result[1] = count;
  
  Rcout << "end_dist_with_gappos" << std::endl;
  return result;
}

//' @title weighted_cdr3_dist
//' @name weighted_cdr3_dist
//' @author Julian Spagnuolo
//' @description 
//'
//' @param 
//' @export
// [[Rcpp::export]]
int weighted_cdr3_dist(std::string cdrx, std::string cdry, bool align, bool trim, int cdr3_weight, int gap_penalty)
{
  int dist;
  int ls;
  int ll;
  int ld;
  int gappos;
  std::vector<int> gap_dist_res;
  
  int min_gappos;
  int max_gappos;
  
  int best_dist;
  int best_count;
  int best_gappos;
  
  Rcout << "start_weighted_cdr3_dist" << std::endl;
  
  if(cdrx.size() >= cdry.size())
  {
    ll = cdrx.size();
    ls = cdry.size();
  }
  else
  {
    ll = cdry.size();
    ls = cdrx.size();
  }
  
  ld = ll - ls;
  
  if(align == false)
  {
    gappos = std::min(6, 3 + (ls - 5)/2 ); // this could result in a double being pushed into an integer. Should be an integer always.
    if(cdrx.size() >= cdry.size())
    {
      gap_dist_res = seq_dist_with_gappos(cdry, cdrx, gappos, trim);
    }
    else
    {
      gap_dist_res = seq_dist_with_gappos(cdrx, cdry, gappos, trim);
    }
    
  }
  else
  {
    min_gappos = 5;
    max_gappos = ls-1-4; // ??
    while(min_gappos > max_gappos)
    {
      min_gappos -= 1;
      max_gappos += 1;
      for(gappos = min_gappos; gappos < max_gappos+1; gappos++)
      {
        if(cdrx.size() >= cdry.size())
        {
          gap_dist_res = seq_dist_with_gappos(cdry, cdrx, gappos, trim);
        }
        else
        {
          gap_dist_res = seq_dist_with_gappos(cdrx, cdry, gappos, trim);
        }
        // should be an assert check to see if count == best_count but best_count is not instantiated in this if loop, so not possible??
        
        if(gappos == min_gappos | gap_dist_res[0] < best_dist) // is the second logic test possible?
        {
          best_dist = gap_dist_res[0];
          best_gappos = gappos;
          best_count = gap_dist_res[1];
        }
      }
    }
  }
  
  dist = cdr3_weight * best_dist * gap_penalty;
  
  Rcout << "end_weighted_cdr3_dist" << std::endl;
  
  return dist;
}

//' @title CDR3dist
//' @name CDR3dist
//' @author Julian Spagnuolo
//' @description 
//'
//' @param 
//' @export
// [[Rcpp::export]]
IntegerMatrix CDR3dist(std::vector<std::string> cdrs, Rcpp::StringVector clones, bool align, bool trim, int cdr3_weight, int gap_penalty)
{
  Rcout << "start" << std::endl;
  
  IntegerMatrix distmat(cdrs.size(), cdrs.size());
  rownames(distmat) = clones;
  colnames(distmat) = clones;
  
  /// put time saving method of calculating only half of the matrix back in!!!! and figure out how to return a dist class object!
  for(int y = 0; y < cdrs.size(); y++)
  {
    for(int x = 0; x < cdrs.size(); x++)
    {
      distmat(x,y) = weighted_cdr3_dist(cdrs[x], cdrs[y], align, trim, cdr3_weight, gap_penalty);
    }
  }
  
  return distmat;
}

//CDR3dist(cdrs=c("SGGSNYKL","SRGSNNRI"),clones=c("a","b"),align = TRUE, trim = FALSE, cdr3_weight = 3, gap_penalty = 4)
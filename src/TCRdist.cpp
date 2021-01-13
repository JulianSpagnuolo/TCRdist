#include <string>
#include <vector>
#include <seqan/score.h>
#include "aligncdr.h"


#include <Rcpp.h>

using namespace seqan;
using namespace Rcpp;


// [[Rcpp::depends(BH)]]
// [[Rcpp::depends(RSeqAn)]]
// [[Rcpp::plugins(cpp14)]]

//' @title TCRdist
//' @name TCRdist
//' @author Julian Spagnuolo
//' @description 
//'
//' @param 
//' @export
// [[Rcpp::export]]
IntegerMatrix CDRdistmat(std::vector<std::string> cdrs, Rcpp::StringVector clones, int cdr)
{
  
  IntegerMatrix distmat(cdrs.size(), cdrs.size());
  rownames(distmat) = clones;
  colnames(distmat) = clones;
  
  /// put time saving method of calculating only half of the matrix back in!!!! and figure out how to return a dist class object!
  for(int y = 0; y < cdrs.size(); y++)
  {
    for(int x = 0; x < cdrs.size(); x++)
    {
      distmat(x,y) = CDRdist(cdrs[x], cdrs[y], cdr);
    }
  }
  
  return distmat;
}


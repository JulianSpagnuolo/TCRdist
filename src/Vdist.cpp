#include <string>
#include <vector>
#include <seqan/score.h>
#include "valign.h"

#include <Rcpp.h>

using namespace seqan;
using namespace Rcpp;

// [[Rcpp::depends(BH)]]
// [[Rcpp::depends(RSeqAn)]]
// [[Rcpp::plugins(cpp14)]]

//' @title Vdist
//' @name Vdist
//' @author Julian Spagnuolo
//' @description compute pair-wise V distances using IMGT CDR1, CDR2 and CDR2.5 alignments
//'
//' @param 
//' @export
// [[Rcpp::export]]
Rcpp::IntegerMatrix Vdist(std::vector<std::string> cdrs, Rcpp::StringVector Vgene, int gap_penalty, int weight){
  
  Rcpp::IntegerMatrix distmat(cdrs.size(), cdrs.size());
  rownames(distmat) = Vgene;
  colnames(distmat) = Vgene;
  
  for(int y = 0; y < cdrs.size(); y++)
  {
    for(int x = y; x < cdrs.size(); x++)
    {
      distmat(x,y) = Vscore(cdrs[x], cdrs[y], gap_penalty, weight);
    }
  }
  
  return distmat;
}

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
int cdrDist(std::string cdrx, std::string cdry, int cdr)
{
  
  int dist;
  int distW;
  
  switch(cdr) // add switch statement to add weight to distance calculations
  {
  case 1: distW = 1;
  case 2: distW = 1;
  case 3: distW = 3;
    break;
  } 
  
  if(cdrx.compare(cdry) == 0) // check if sequence is identical
  {
    dist = 0;
  }
  else // compare lengths
  {
    std::vector<std::string> gapped;
    gapped = align(cdrx, cdry);
    
    //std::cout << gapped << std::endl;
    // compare characters in aligned sequences.
    
    
  }
  
  dist = 0;
  
  
  return dist;
}



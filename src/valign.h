#ifndef VALIGN_H
#define VALIGN_H


#include <string>
#include <vector>
#include <seqan/score.h>

#include <Rcpp.h>

// [[Rcpp::depends(BH)]]
// [[Rcpp::depends(RSeqAn)]]
// [[Rcpp::plugins(cpp14)]]

using namespace seqan;
using namespace Rcpp;

int blosum_aa_distance(char aax, char aay, int gap_penalty){
  
  int aascore = 0;
  
  if(aax == '.' & aay == '.')
  {
    aascore = 0;
  }
  else if(aax == '.' | aay == '.')
  {
    aascore = gap_penalty;
  }
  else
  {
    if(aax == aay)
    {
      aascore = 0;
    }
    else if(score(seqan::Blosum62(), aax, aay) < 0)
    {
      aascore = 4;
    }
    else
    {
      aascore = 4 - score(seqan::Blosum62(), aax, aay);
    }
  }
  
  
  return aascore;
}

int Vscore(std::string cdrx, std::string cdry, int gap_penalty, int weight){
  
  int dist = 0;
  if(cdrx.compare(cdry) == 1)
  {
    return dist;
  }
  else
  {
    for(int i = 0; i < cdrx.length(); i++)
    {
      dist += blosum_aa_distance(cdrx[i], cdry[i], gap_penalty) * weight;
    }
  }
  
  
  return dist;
}

#endif
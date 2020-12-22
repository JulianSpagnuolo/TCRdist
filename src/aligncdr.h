#ifndef ALIGNCDR_H
#define ALIGNCDR_H


#include <string>
#include <vector>
#include <seqan/score.h>

#include <Rcpp.h>

// [[Rcpp::depends(BH)]]
// [[Rcpp::depends(RSeqAn)]]
// [[Rcpp::plugins(cpp14)]]

using namespace seqan;
using namespace Rcpp;


std::vector<std::string> align(std::string cdrx, std::string cdry)
{
  std::string s0;
  std::string s1;
  std::vector<std::string> output;
  
  int best_score = -1000;
  int best_gappos = 0;
  
  if(cdrx.length() < cdry.length())
  {
    s0 = cdrx;
    s1 = cdry;
  }else{
    s0 = cdry;
    s1 = cdrx;
  }
  
  int lDiff;
  lDiff = s1.length() - s0.length();
  
  for(int g = 0; g < s0.length()-1; g++)
  {
    int alscore = 0;
    
    for(int i = 0; i < g+1; i++)
    {
      alscore += score(seqan::Blosum62(), s0[i], s1[i]);
    }
    for(int i = g+1; i < s0.length(); i++)
    { 
      alscore += score(seqan::Blosum62(), s0[i], s1[i+lDiff]);
    }
    
    if(alscore > best_score)
    {
      best_score = alscore;
      best_gappos = g;
    }
  }
  
  // insert the gap
  s0.insert(best_gappos+1, lDiff, '-');
  
  if(cdrx.length() < cdry.length())
  {
    output = {s0, s1};
  }else{
    output = {s1, s0};
  }
  return output;
}

int AAdist(char AAx, char AAy)
{
  int dist;
  if(AAx == AAy)
  {
    dist = 0;
  }
  else
  {
    if(score(seqan::Blosum62(), AAx, AAy) < 0)
    {
      dist = 4;
    }
    else
    {
      dist = 4 - score(seqan::Blosum62(), AAx, AAy);
    }
  }
  return dist;
}

int CDRdist(std::string cdrx, std::string cdry, int cdr) {
  
  int distW;
  int score = 0;
  switch(cdr)
  {
  case 1: distW = 1;
  case 2: distW = 1;
  case 3: distW = 3;
  }
  
  std::vector<std::string> alignobj;
  alignobj = align(cdrx, cdry);
  
  if(alignobj[0].length() == alignobj[1].length())
  {
    for(int i = 0; i < alignobj[0].length(); i++)
    {
      score += AAdist(alignobj[0][i], alignobj[1][i]) * distW;
    }
  }else
  {
    std::cout << "aligned lengths not equal!" << std::endl;
    return -66;
  }
  
  return score;
}

IntegerMatrix CDRdistmat(std::vector<std::string> cdrx, std::vector<std::string> cdry, int cdr)
{
  
  IntegerMatrix distmat(cdrx.size(), cdry.size());
  
  for(int x = 0; x < cdrx.size(); x++)
  {
    for(int y = x; y < cdry.size(); y++)
    {
      distmat(x,y) = CDRdist(cdrx[x], cdry[y], cdr);
    }
  }
  return distmat;
}



#endif
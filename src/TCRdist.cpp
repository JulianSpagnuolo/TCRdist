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
int TCRdist(Matrix TCRseq, bool CDR3)
{
  // if alpha/beta matrix, ncol is even
  if(TCRseq.ncol() % 2 == 0 & CDR3 == 1)
  {
    std::cout << "Running alpha/beta" << std::endl;
  }else if(TCRseq.ncol() % 2 != 0)
  {
    std::cout << "Running single chain" << std::endl;
  }else if(CDR3 == 0)
  {
    std::cout << "Running CDR1 & CDR2 only" << std::endl;
    if(TCRseq.ncol() == 2)
    {
      std::cout << "Running single chain CDR1 & CDR2" << std::endl;
    }else if(TCRseq.ncol() == 4)
    {
      std::cout << "Running alpha/beta CDR1 & CDR2" << std::endl;
    }
    
  }
  
  
  
  return 0;
}


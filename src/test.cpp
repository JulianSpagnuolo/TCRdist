#include <string>
#include <vector>
#include <seqan/score.h>

#include <Rcpp.h>

using namespace seqan;

// [[Rcpp::depends(BH)]]
// [[Rcpp::depends(RSeqAn)]]
// [[Rcpp::plugins(cpp14)]]
using namespace Rcpp;


// distance calculator



//' @title TCRdist
//' @name TCRdist
//' @author Julian Spagnuolo
//' @description 
//'
//' @param cdr1, matrix
//' @export
// [[Rcpp::export]]
int test(std::string cdrx, std::string cdry)
{
  
  std::string str("lolcat");
  str.insert(0, 5, '.');
  
  std::cout << str << std::endl;
  
  return 0;
}


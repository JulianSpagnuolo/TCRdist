#include <string>
#include <vector>

#include <Rcpp.h>

using namespace Rcpp;

// [[Rcpp::plugins(cpp14)]]

//' @title trimmer
//' @name trimmer
//' @author Julian Spagnuolo
//' @description trims V and J sequences from CDR3 amino acid sequences based on the IMGT reference.
//'
//' @param 
//' @export
// [[Rcpp::export]]
std::vector<std::string> trimmer(std::string cdr3, std::string vpart, std::string jpart) {
  
  std::vector<std::string> output (3);
  
  int v;
  int j;
  
  if(vpart.size() == 0 || jpart.size() == 0)
  {
    return output;
  }
  
  for(int i = 0; i < vpart.size(); i++)
    {
      if(vpart[i] != cdr3[i])
      {
        // end of v part
        v = i;
        output[0] = vpart.substr(0, i);
      }
    }
  
  
  for(int i = 0; i < jpart.size(); i++)
    {
      if(jpart[jpart.size() - i] != cdr3[cdr3.size() - i])
      {
        // end of j part
        j = i - 1;
        output[2] = jpart.substr(jpart.size() - j, i);
      }
    }
  
  int n = cdr3.size();
  n = n - output[2].size();
  n = n - output[0].size();
  
  output[1] = cdr3.substr(v, n);
  
  return output;
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//

/*** R
trimmer("CASSKLQGADEQYF", "CASSY", "SYEQYF") #  TRBV6-5*01    TRBD1*01  TRBJ2-7*01
*/

// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// cdrDist
int cdrDist(std::string cdrx, std::string cdry, int cdr);
RcppExport SEXP _TCRdist_cdrDist(SEXP cdrxSEXP, SEXP cdrySEXP, SEXP cdrSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type cdrx(cdrxSEXP);
    Rcpp::traits::input_parameter< std::string >::type cdry(cdrySEXP);
    Rcpp::traits::input_parameter< int >::type cdr(cdrSEXP);
    rcpp_result_gen = Rcpp::wrap(cdrDist(cdrx, cdry, cdr));
    return rcpp_result_gen;
END_RCPP
}
// test
int test(std::string cdrx, std::string cdry);
RcppExport SEXP _TCRdist_test(SEXP cdrxSEXP, SEXP cdrySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type cdrx(cdrxSEXP);
    Rcpp::traits::input_parameter< std::string >::type cdry(cdrySEXP);
    rcpp_result_gen = Rcpp::wrap(test(cdrx, cdry));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_TCRdist_cdrDist", (DL_FUNC) &_TCRdist_cdrDist, 3},
    {"_TCRdist_test", (DL_FUNC) &_TCRdist_test, 2},
    {NULL, NULL, 0}
};

RcppExport void R_init_TCRdist(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}

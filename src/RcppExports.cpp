// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// dgCMatrix_colSums2
NumericVector dgCMatrix_colSums2(S4 matrix, bool na_rm);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colSums2(SEXP matrixSEXP, SEXP na_rmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colSums2(matrix, na_rm));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colMeans2
NumericVector dgCMatrix_colMeans2(S4 matrix, bool na_rm);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colMeans2(SEXP matrixSEXP, SEXP na_rmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colMeans2(matrix, na_rm));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colMedians
NumericVector dgCMatrix_colMedians(S4 matrix, bool na_rm);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colMedians(SEXP matrixSEXP, SEXP na_rmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colMedians(matrix, na_rm));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colVars
NumericVector dgCMatrix_colVars(S4 matrix, bool na_rm, Nullable<NumericVector> center);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colVars(SEXP matrixSEXP, SEXP na_rmSEXP, SEXP centerSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    Rcpp::traits::input_parameter< Nullable<NumericVector> >::type center(centerSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colVars(matrix, na_rm, center));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colMads
NumericVector dgCMatrix_colMads(S4 matrix, bool na_rm, double scale_factor);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colMads(SEXP matrixSEXP, SEXP na_rmSEXP, SEXP scale_factorSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    Rcpp::traits::input_parameter< double >::type scale_factor(scale_factorSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colMads(matrix, na_rm, scale_factor));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colMins
NumericVector dgCMatrix_colMins(S4 matrix, bool na_rm);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colMins(SEXP matrixSEXP, SEXP na_rmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colMins(matrix, na_rm));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colMaxs
NumericVector dgCMatrix_colMaxs(S4 matrix, bool na_rm);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colMaxs(SEXP matrixSEXP, SEXP na_rmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colMaxs(matrix, na_rm));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colOrderStats
NumericVector dgCMatrix_colOrderStats(S4 matrix, int which, bool na_rm);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colOrderStats(SEXP matrixSEXP, SEXP whichSEXP, SEXP na_rmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< int >::type which(whichSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colOrderStats(matrix, which, na_rm));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colLogSumExps
NumericVector dgCMatrix_colLogSumExps(S4 matrix, bool na_rm);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colLogSumExps(SEXP matrixSEXP, SEXP na_rmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colLogSumExps(matrix, na_rm));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colProds
NumericVector dgCMatrix_colProds(S4 matrix, bool na_rm);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colProds(SEXP matrixSEXP, SEXP na_rmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colProds(matrix, na_rm));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colWeightedMeans
NumericVector dgCMatrix_colWeightedMeans(S4 matrix, NumericVector weights, bool na_rm);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colWeightedMeans(SEXP matrixSEXP, SEXP weightsSEXP, SEXP na_rmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type weights(weightsSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colWeightedMeans(matrix, weights, na_rm));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colWeightedVars
NumericVector dgCMatrix_colWeightedVars(S4 matrix, NumericVector weights, bool na_rm);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colWeightedVars(SEXP matrixSEXP, SEXP weightsSEXP, SEXP na_rmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type weights(weightsSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colWeightedVars(matrix, weights, na_rm));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colCounts
IntegerVector dgCMatrix_colCounts(S4 matrix, double value, bool na_rm);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colCounts(SEXP matrixSEXP, SEXP valueSEXP, SEXP na_rmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< double >::type value(valueSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colCounts(matrix, value, na_rm));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colAnyNAs
LogicalVector dgCMatrix_colAnyNAs(S4 matrix);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colAnyNAs(SEXP matrixSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colAnyNAs(matrix));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colAnys
LogicalVector dgCMatrix_colAnys(S4 matrix, double value, bool na_rm);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colAnys(SEXP matrixSEXP, SEXP valueSEXP, SEXP na_rmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< double >::type value(valueSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colAnys(matrix, value, na_rm));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colAlls
LogicalVector dgCMatrix_colAlls(S4 matrix, double value, bool na_rm);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colAlls(SEXP matrixSEXP, SEXP valueSEXP, SEXP na_rmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< double >::type value(valueSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colAlls(matrix, value, na_rm));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colQuantiles
NumericMatrix dgCMatrix_colQuantiles(S4 matrix, NumericVector probs, bool na_rm);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colQuantiles(SEXP matrixSEXP, SEXP probsSEXP, SEXP na_rmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type probs(probsSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colQuantiles(matrix, probs, na_rm));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colTabulate
IntegerMatrix dgCMatrix_colTabulate(S4 matrix, NumericVector sorted_unique_values);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colTabulate(SEXP matrixSEXP, SEXP sorted_unique_valuesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type sorted_unique_values(sorted_unique_valuesSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colTabulate(matrix, sorted_unique_values));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colCumsums
NumericMatrix dgCMatrix_colCumsums(S4 matrix);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colCumsums(SEXP matrixSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colCumsums(matrix));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colCumprods
NumericMatrix dgCMatrix_colCumprods(S4 matrix);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colCumprods(SEXP matrixSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colCumprods(matrix));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colCummins
NumericMatrix dgCMatrix_colCummins(S4 matrix);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colCummins(SEXP matrixSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colCummins(matrix));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colCummaxs
NumericMatrix dgCMatrix_colCummaxs(S4 matrix);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colCummaxs(SEXP matrixSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colCummaxs(matrix));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colRanks_num
NumericMatrix dgCMatrix_colRanks_num(S4 matrix, std::string ties_method, std::string na_handling, bool preserve_shape);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colRanks_num(SEXP matrixSEXP, SEXP ties_methodSEXP, SEXP na_handlingSEXP, SEXP preserve_shapeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< std::string >::type ties_method(ties_methodSEXP);
    Rcpp::traits::input_parameter< std::string >::type na_handling(na_handlingSEXP);
    Rcpp::traits::input_parameter< bool >::type preserve_shape(preserve_shapeSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colRanks_num(matrix, ties_method, na_handling, preserve_shape));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_colRanks_int
IntegerMatrix dgCMatrix_colRanks_int(S4 matrix, std::string ties_method, std::string na_handling, bool preserve_shape);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_colRanks_int(SEXP matrixSEXP, SEXP ties_methodSEXP, SEXP na_handlingSEXP, SEXP preserve_shapeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< std::string >::type ties_method(ties_methodSEXP);
    Rcpp::traits::input_parameter< std::string >::type na_handling(na_handlingSEXP);
    Rcpp::traits::input_parameter< bool >::type preserve_shape(preserve_shapeSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_colRanks_int(matrix, ties_method, na_handling, preserve_shape));
    return rcpp_result_gen;
END_RCPP
}
// quantile_sparse
double quantile_sparse(NumericVector values, int number_of_zeros, double prob);
RcppExport SEXP _sparseMatrixStats_quantile_sparse(SEXP valuesSEXP, SEXP number_of_zerosSEXP, SEXP probSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type values(valuesSEXP);
    Rcpp::traits::input_parameter< int >::type number_of_zeros(number_of_zerosSEXP);
    Rcpp::traits::input_parameter< double >::type prob(probSEXP);
    rcpp_result_gen = Rcpp::wrap(quantile_sparse(values, number_of_zeros, prob));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_rowSums2
NumericVector dgCMatrix_rowSums2(S4 matrix, bool na_rm);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_rowSums2(SEXP matrixSEXP, SEXP na_rmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_rowSums2(matrix, na_rm));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_rowMeans2
NumericVector dgCMatrix_rowMeans2(S4 matrix, bool na_rm);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_rowMeans2(SEXP matrixSEXP, SEXP na_rmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_rowMeans2(matrix, na_rm));
    return rcpp_result_gen;
END_RCPP
}
// dgCMatrix_rowVars
NumericVector dgCMatrix_rowVars(S4 matrix, bool na_rm, Nullable<NumericVector> center);
RcppExport SEXP _sparseMatrixStats_dgCMatrix_rowVars(SEXP matrixSEXP, SEXP na_rmSEXP, SEXP centerSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< S4 >::type matrix(matrixSEXP);
    Rcpp::traits::input_parameter< bool >::type na_rm(na_rmSEXP);
    Rcpp::traits::input_parameter< Nullable<NumericVector> >::type center(centerSEXP);
    rcpp_result_gen = Rcpp::wrap(dgCMatrix_rowVars(matrix, na_rm, center));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_sparseMatrixStats_dgCMatrix_colSums2", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colSums2, 2},
    {"_sparseMatrixStats_dgCMatrix_colMeans2", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colMeans2, 2},
    {"_sparseMatrixStats_dgCMatrix_colMedians", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colMedians, 2},
    {"_sparseMatrixStats_dgCMatrix_colVars", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colVars, 3},
    {"_sparseMatrixStats_dgCMatrix_colMads", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colMads, 3},
    {"_sparseMatrixStats_dgCMatrix_colMins", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colMins, 2},
    {"_sparseMatrixStats_dgCMatrix_colMaxs", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colMaxs, 2},
    {"_sparseMatrixStats_dgCMatrix_colOrderStats", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colOrderStats, 3},
    {"_sparseMatrixStats_dgCMatrix_colLogSumExps", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colLogSumExps, 2},
    {"_sparseMatrixStats_dgCMatrix_colProds", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colProds, 2},
    {"_sparseMatrixStats_dgCMatrix_colWeightedMeans", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colWeightedMeans, 3},
    {"_sparseMatrixStats_dgCMatrix_colWeightedVars", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colWeightedVars, 3},
    {"_sparseMatrixStats_dgCMatrix_colCounts", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colCounts, 3},
    {"_sparseMatrixStats_dgCMatrix_colAnyNAs", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colAnyNAs, 1},
    {"_sparseMatrixStats_dgCMatrix_colAnys", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colAnys, 3},
    {"_sparseMatrixStats_dgCMatrix_colAlls", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colAlls, 3},
    {"_sparseMatrixStats_dgCMatrix_colQuantiles", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colQuantiles, 3},
    {"_sparseMatrixStats_dgCMatrix_colTabulate", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colTabulate, 2},
    {"_sparseMatrixStats_dgCMatrix_colCumsums", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colCumsums, 1},
    {"_sparseMatrixStats_dgCMatrix_colCumprods", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colCumprods, 1},
    {"_sparseMatrixStats_dgCMatrix_colCummins", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colCummins, 1},
    {"_sparseMatrixStats_dgCMatrix_colCummaxs", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colCummaxs, 1},
    {"_sparseMatrixStats_dgCMatrix_colRanks_num", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colRanks_num, 4},
    {"_sparseMatrixStats_dgCMatrix_colRanks_int", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_colRanks_int, 4},
    {"_sparseMatrixStats_quantile_sparse", (DL_FUNC) &_sparseMatrixStats_quantile_sparse, 3},
    {"_sparseMatrixStats_dgCMatrix_rowSums2", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_rowSums2, 2},
    {"_sparseMatrixStats_dgCMatrix_rowMeans2", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_rowMeans2, 2},
    {"_sparseMatrixStats_dgCMatrix_rowVars", (DL_FUNC) &_sparseMatrixStats_dgCMatrix_rowVars, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_sparseMatrixStats(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}

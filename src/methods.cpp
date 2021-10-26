#include <Rcpp.h>
#include "SparseMatrixView.h"
#include "ColumnView.h"
#include "VectorSubsetView.h"
#include "SkipNAVectorSubsetView.h"
#include "quantile.h"
#include "sample_rank.h"
#include "my_utils.h"

using namespace Rcpp;



template<typename Functor>
NumericVector reduce_matrix_double(S4 matrix, bool na_rm, Functor op){
  dgCMatrixView sp_mat = wrap_dgCMatrix(matrix);
  ColumnView cv(&sp_mat);
  std::vector<double> result;
  result.reserve(sp_mat.ncol);
  if(na_rm){
    std::transform(cv.begin(), cv.end(), std::back_inserter(result),
      [op](ColumnView::col_container col) -> double {
        SkipNAVectorSubsetView<REALSXP> values_wrapper(&col.values);
        SkipNAVectorSubsetView<INTSXP> row_indices_wrapper(&col.row_indices);
        return op(values_wrapper, row_indices_wrapper, col.number_of_zeros);
      });
  }else{
    std::transform(cv.begin(), cv.end(), std::back_inserter(result),
      [op](ColumnView::col_container col) -> double {
        return op(col.values, col.row_indices, col.number_of_zeros);
      });
  }
  return wrap(result);
}

template<typename Functor>
IntegerVector reduce_matrix_int(S4 matrix, bool na_rm, Functor op){
  dgCMatrixView sp_mat = wrap_dgCMatrix(matrix);
  ColumnView cv(&sp_mat);
  std::vector<int> result;
  result.reserve(sp_mat.ncol);
  if(na_rm){
    std::transform(cv.begin(), cv.end(), std::back_inserter(result),
                   [op](ColumnView::col_container col) -> int {
                     SkipNAVectorSubsetView<REALSXP> values_wrapper(&col.values);
                     SkipNAVectorSubsetView<INTSXP> row_indices_wrapper(&col.row_indices);
                     return op(values_wrapper, row_indices_wrapper, col.number_of_zeros);
                   });
  }else{
    std::transform(cv.begin(), cv.end(), std::back_inserter(result),
                   [op](ColumnView::col_container col) -> int {
                     return op(col.values, col.row_indices, col.number_of_zeros);
                   });
  }
  return wrap(result);
}

template<typename Functor>
LogicalVector reduce_matrix_lgl(S4 matrix, bool na_rm, Functor op){
  dgCMatrixView sp_mat = wrap_dgCMatrix(matrix);
  ColumnView cv(&sp_mat);
  std::vector<int> result;
  result.reserve(sp_mat.ncol);
  if(na_rm){
    std::transform(cv.begin(), cv.end(), std::back_inserter(result),
                   [op](ColumnView::col_container col) -> int {
                     SkipNAVectorSubsetView<REALSXP> values_wrapper(&col.values);
                     SkipNAVectorSubsetView<INTSXP> row_indices_wrapper(&col.row_indices);
                     return op(values_wrapper, row_indices_wrapper, col.number_of_zeros);
                   });
  }else{
    std::transform(cv.begin(), cv.end(), std::back_inserter(result),
                   [op](ColumnView::col_container col) -> int {
                     return op(col.values, col.row_indices, col.number_of_zeros);
                   });
  }
  return wrap(result);
}


template<typename Functor>
NumericVector reduce_matrix_double_with_index(S4 matrix, bool na_rm, Functor op){
  dgCMatrixView sp_mat = wrap_dgCMatrix(matrix);
  ColumnView cv(&sp_mat);
  int ncol =  sp_mat.ncol;
  NumericVector result(ncol);
  if(na_rm){
    ColumnView::iterator col_iter = cv.begin();
    for(int col_idx = 0; col_idx < ncol; col_idx++){
      ColumnView::col_container col = *col_iter;
      SkipNAVectorSubsetView<REALSXP> values_wrapper(&col.values);
      SkipNAVectorSubsetView<INTSXP> row_indices_wrapper(&col.row_indices);
      result[col_idx] = op(values_wrapper, row_indices_wrapper, col.number_of_zeros, col_idx);
      ++col_iter;
    }
  }else{
    ColumnView::iterator col_iter = cv.begin();
    for(int col_idx = 0; col_idx < ncol; col_idx++){
      ColumnView::col_container col = *col_iter;
      result[col_idx] = op(col.values, col.row_indices, col.number_of_zeros, col_idx);
      ++col_iter;
    }
  }
  return result;
}

template<typename Functor>
NumericMatrix reduce_matrix_num_matrix(S4 matrix, bool na_rm, R_len_t n_res_columns, bool transpose, Functor op){
  dgCMatrixView sp_mat = wrap_dgCMatrix(matrix);
  ColumnView cv(&sp_mat);
  std::vector<std::vector<double> > result;
  result.reserve(sp_mat.ncol);
  if(na_rm){
    std::transform(cv.begin(), cv.end(), std::back_inserter(result),
                   [op](ColumnView::col_container col) -> std::vector<double> {
                     SkipNAVectorSubsetView<REALSXP> values_wrapper(&col.values);
                     SkipNAVectorSubsetView<INTSXP> row_indices_wrapper(&col.row_indices);
                     return op(values_wrapper, row_indices_wrapper, col.number_of_zeros);
                   });
  }else{
    std::transform(cv.begin(), cv.end(), std::back_inserter(result),
                   [op](ColumnView::col_container col) -> std::vector<double> {
                     return op(col.values, col.row_indices, col.number_of_zeros);
                   });
  }
  std::vector<double> result_flat = flatten(result);
  if(transpose){
    return Rcpp::transpose(NumericMatrix(n_res_columns, sp_mat.ncol, result_flat.begin()));
  }else{
    return NumericMatrix(n_res_columns, sp_mat.ncol, result_flat.begin());
  }
}

template<typename Functor>
NumericMatrix reduce_matrix_num_matrix_with_na(S4 matrix, R_len_t n_res_columns, bool transpose, Functor op){
  dgCMatrixView sp_mat = wrap_dgCMatrix(matrix);
  ColumnView cv(&sp_mat);
  std::vector<std::vector<double> > result;
  result.reserve(sp_mat.ncol);
  std::transform(cv.begin(), cv.end(), std::back_inserter(result),
                 [op](ColumnView::col_container col) -> std::vector<double> {
                   return op(col.values, col.row_indices, col.number_of_zeros);
                 });
  std::vector<double> result_flat = flatten(result);
  if(transpose){
    return Rcpp::transpose(NumericMatrix(n_res_columns, sp_mat.ncol, result_flat.begin()));
  }else{
    return NumericMatrix(n_res_columns, sp_mat.ncol, result_flat.begin());
  }
}


template<typename Functor>
IntegerMatrix reduce_matrix_int_matrix(S4 matrix, bool na_rm, R_len_t n_res_columns, bool transpose, Functor op){
  dgCMatrixView sp_mat = wrap_dgCMatrix(matrix);
  ColumnView cv(&sp_mat);
  std::vector<std::vector<int> > result;
  result.reserve(sp_mat.ncol);
  if(na_rm){
    std::transform(cv.begin(), cv.end(), std::back_inserter(result),
                   [op](ColumnView::col_container col) -> std::vector<int> {
                     SkipNAVectorSubsetView<REALSXP> values_wrapper(&col.values);
                     SkipNAVectorSubsetView<INTSXP> row_indices_wrapper(&col.row_indices);
                     return op(values_wrapper, row_indices_wrapper, col.number_of_zeros);
                   });
  }else{
    std::transform(cv.begin(), cv.end(), std::back_inserter(result),
                   [op](ColumnView::col_container col) -> std::vector<int> {
                     return op(col.values, col.row_indices, col.number_of_zeros);
                   });
  }
  std::vector<int> result_flat = flatten(result);
  if(transpose){
    return Rcpp::transpose(IntegerMatrix(n_res_columns, sp_mat.ncol, result_flat.begin()));
  }else{
    return IntegerMatrix(n_res_columns, sp_mat.ncol, result_flat.begin());
  }
}

template<typename Functor>
IntegerMatrix reduce_matrix_int_matrix_with_na(S4 matrix, R_len_t n_res_columns, bool transpose, Functor op){
  dgCMatrixView sp_mat = wrap_dgCMatrix(matrix);
  ColumnView cv(&sp_mat);
  std::vector<std::vector<int> > result;
  result.reserve(sp_mat.ncol);
  std::transform(cv.begin(), cv.end(), std::back_inserter(result),
                 [op](ColumnView::col_container col) -> std::vector<int> {
                   return op(col.values, col.row_indices, col.number_of_zeros);
                 });
  std::vector<int> result_flat = flatten(result);
  if(transpose){
    return Rcpp::transpose(IntegerMatrix(n_res_columns, sp_mat.ncol, result_flat.begin()));
  }else{
    return IntegerMatrix(n_res_columns, sp_mat.ncol, result_flat.begin());
  }
}



/*---------------Simple Aggregation Functions-----------------*/


class colSums2 {
public:
  colSums2() {}
  template<class V, class R>
  double operator()(V& values, R& row_indices, int number_of_zeros) const {
    return sum_stable(values);
  }
};

// [[Rcpp::export]]
NumericVector dgCMatrix_colSums2(S4 matrix, bool na_rm){
  return reduce_matrix_double(matrix, na_rm, colSums2());
}


template<typename Iterator>
inline double sp_mean(Iterator values, int number_of_zeros){
  LDOUBLE sum = 0.0;
  int size = number_of_zeros;
  for(double d : values){
    R_CHECK_USER_INTERRUPT(++size);
    sum += d;
  }
  if(NumericVector::is_na(sum)){
    return sum;
  }else if(size == 0){
    return R_NaN;
  }else{
    return sum / size;
  }
}

class colMeans2 {
public:
  colMeans2() {}
  template<class V, class R>
  double operator()(V& values, R& row_indices, int number_of_zeros) const {
    return sp_mean(values, number_of_zeros);
  }
};

// [[Rcpp::export]]
NumericVector dgCMatrix_colMeans2(S4 matrix, bool na_rm){
  return reduce_matrix_double(matrix, na_rm, colMeans2());
}


class colMedians {
public:
  colMedians(bool na_rm_) : na_rm(na_rm_) {}
  template<class V, class R>
  double operator()(V& values, R& row_indices, int number_of_zeros) const {
    if(! na_rm){
      bool any_na = is_any_na(values);
      if(any_na){
        return NA_REAL;
      }
    }
    R_len_t size = values.size();
    if(number_of_zeros > size){
      // Easy escape hatch
      return 0.0;
    }
    if(size + number_of_zeros == 0){
      return NA_REAL;
    }
    return quantile_sparse_impl(values, number_of_zeros, 0.5);
  }
private:
  bool na_rm;
};

// [[Rcpp::export]]
NumericVector dgCMatrix_colMedians(S4 matrix, bool na_rm){
  return reduce_matrix_double(matrix, na_rm, colMedians(na_rm));
}


class colVars {
public:
  colVars(NumericVector center_vec_, bool center_provided_) :
    center_vec(center_vec_),
    center_provided(center_provided_) {}

  template<class V, class R>
  double operator()(V& values, R& row_indices, int number_of_zeros, int col_idx) const {
    double mean = 0;
    if(! center_provided){
      mean = sp_mean(values, number_of_zeros);
    }else{
      mean = center_vec[col_idx];
    }
    if(ISNA(mean)){
      return NA_REAL;
    }
    double sigma2 = number_of_zeros * mean * mean;
    double diff = 0.0;
    int size = number_of_zeros;
    for(double d : values){
      R_CHECK_USER_INTERRUPT(++size);
      diff = d - mean;
      sigma2 += diff * diff;
    }
    if(size <= 1){
      return NA_REAL;    // Yes, var(3) actually returns NA instead of NaN
    }else{
      return sigma2  / (size-1);
    }
  }

private:
  NumericVector center_vec;
  bool center_provided;
};

// [[Rcpp::export]]
NumericVector dgCMatrix_colVars(S4 matrix, bool na_rm, Nullable<NumericVector> center){
  bool center_provided = center.isNotNull();
  NumericVector center_vec(0);
  if(center_provided){
    center_vec = Rcpp::as<NumericVector>(center.get());
  }
  return reduce_matrix_double_with_index(matrix, na_rm, colVars(center_vec, center_provided));
}


class colMads {
public:
  colMads(bool na_rm_, double scale_factor_, NumericVector center_vec_, bool center_provided_) :
  na_rm(na_rm_),
  scale_factor(scale_factor_),
  center_vec(center_vec_),
  center_provided(center_provided_) {}

  template<class V, class R>
  double operator()(V& values, R& row_indices, int number_of_zeros, int col_idx) const {
    if(! na_rm){
      bool any_na = is_any_na(values);
      if(any_na){
        return NA_REAL;
      }
    }
    R_len_t size = values.size();
    if(! center_provided && number_of_zeros > size){
      // Easy escape hatch
      return 0.0;
    }
    if(size + number_of_zeros == 0){
      return NA_REAL;
    }
    double med = 0;
    if(center_provided){
      med = center_vec[col_idx];
    }else{
      med = quantile_sparse_impl(values, number_of_zeros, 0.5);
    }
    NumericVector complete_vector(size + number_of_zeros, std::abs(med));
    auto val_it = values.begin();
    auto val_end = values.end();
    auto ind_it = row_indices.begin();
    auto ind_end = row_indices.end();
    while(val_it != val_end && ind_it != ind_end){
      complete_vector[*ind_it] = std::abs(*val_it - med);
      ++val_it;
      ++ind_it;
    }
    return median(complete_vector) * scale_factor;
  }
private:
  bool na_rm;
  double scale_factor;
  NumericVector center_vec;
  bool center_provided;
};


// [[Rcpp::export]]
NumericVector dgCMatrix_colMads(S4 matrix, bool na_rm, double scale_factor, Nullable<NumericVector> center){
  bool center_provided = center.isNotNull();
  NumericVector center_vec(0);
  if(center_provided){
    center_vec = Rcpp::as<NumericVector>(center.get());
  }
  return reduce_matrix_double_with_index(matrix, na_rm, colMads(na_rm, scale_factor, center_vec, center_provided));
}



class colMins {
public:
  colMins(bool na_rm_) : na_rm(na_rm_) {}
  template<class V, class R>
  double operator()(V& values, R& row_indices, int number_of_zeros) const {
    if(! na_rm && is_any_na(values)){
      return NA_REAL;
    }
    auto min_iter = std::min_element(values.begin(), values.end(), [](double a, double b) -> bool {
      return a < b;
    });
    if(min_iter == values.end()){
      return number_of_zeros > 0 ? 0.0 : R_PosInf;
    }else{
      return number_of_zeros > 0 ? std::min(*min_iter, 0.0) : *min_iter;
    }
  }
private:
  bool na_rm;
};


// [[Rcpp::export]]
NumericVector dgCMatrix_colMins(S4 matrix, bool na_rm){
  return reduce_matrix_double(matrix, na_rm, colMins(na_rm));
}

class colMaxs {
public:
  colMaxs(bool na_rm_) : na_rm(na_rm_) {}
  template<class V, class R>
  double operator()(V& values, R& row_indices, int number_of_zeros) const {
    if(! na_rm && is_any_na(values)){
      return NA_REAL;
    }
    auto max_iter = std::max_element(values.begin(), values.end(), [](double a, double b) -> bool {
      return a < b;
    });
    if(max_iter == values.end()){
      return number_of_zeros > 0 ? 0.0 : R_NegInf;
    }else{
      return number_of_zeros > 0 ? std::max(*max_iter, 0.0) : *max_iter;
    }
  }
private:
  bool na_rm;
};


// [[Rcpp::export]]
NumericVector dgCMatrix_colMaxs(S4 matrix, bool na_rm){
  return reduce_matrix_double(matrix, na_rm, colMaxs(na_rm));
}


class colOrderStats {
public:
  colOrderStats(bool na_rm_, int which_) : na_rm(na_rm_), which(which_) {}
  template<class V, class R>
  double operator()(V& values, R& row_indices, int number_of_zeros) const {
    if(! na_rm){
      bool any_na = is_any_na(values);
      if(any_na){
        return NA_REAL;
      }
    }
    R_len_t size = values.size();
    double used_which = std::min(which, size + number_of_zeros);
    if(used_which == 0){
      return NA_REAL;
    }else if(size == 0){
      return 0.0;
    }
    std::vector<double> sorted_values;
    std::copy(values.begin(), values.end(), std::back_inserter(sorted_values));
    std::sort(sorted_values.begin(), sorted_values.end(),[](double i1, double i2){
      if(Rcpp::NumericVector::is_na(i1)) return false;
      if(Rcpp::NumericVector::is_na(i2)) return true;
      return i1 < i2;
    });
    bool left_of_zero = sorted_values[0] < 0;
    bool right_of_zero = !left_of_zero && number_of_zeros == 0;
    int zero_counter = ! left_of_zero && ! right_of_zero;
    int vec_counter = 0;
    for(int i = 0; i < sorted_values.size() + number_of_zeros; i++){
      // Rcout << i << " " << vec_counter << " " << zero_counter << " " << left_of_zero << " " << right_of_zero << " " << std::endl;
      if(i == used_which - 1){
        if(! left_of_zero && ! right_of_zero){
          return 0;
        }else{
          return sorted_values[vec_counter];
        }
      }

      if(left_of_zero){
        vec_counter++;
        if(vec_counter == size || sorted_values[vec_counter] > 0){
          left_of_zero = false;
        }
      }
      if(right_of_zero){
        vec_counter++;
      }
      if(! left_of_zero && ! right_of_zero){
        zero_counter++;
        if(zero_counter > number_of_zeros){
          right_of_zero = true;
        }
      }
    }
    return NA_REAL;
  }
  private:
    bool na_rm;
    int which;
  };

// [[Rcpp::export]]
NumericVector dgCMatrix_colOrderStats(S4 matrix, int which, bool na_rm){
  return reduce_matrix_double(matrix, na_rm, colOrderStats(na_rm, which));
}


class colLogSumExps {
public:
  colLogSumExps() {}
  template<class V, class R>
  double operator()(V& values, R& row_indices, int number_of_zeros) const {
    auto max_iter = std::max_element(values.begin(), values.end(), [](double a, double b) -> bool {
      return a < b;
    });
    if(max_iter == values.end()){
      return number_of_zeros > 0 ? std::log(number_of_zeros) : R_NegInf;
    }else{
      double max = *max_iter;
      if(NumericVector::is_na(max)){
        return max;
      }
      if(max == R_PosInf){
        return R_PosInf;
      }
      if(max == R_NegInf){
        return std::log(number_of_zeros);
      }
      double sum = std::accumulate(values.begin(), values.end(), 0.0, [max](double a, double b) -> double {
        return a + exp(b-max);
      });
      sum += exp(-max) * number_of_zeros;
      return max + log(sum);
    }
  }
};

// [[Rcpp::export]]
NumericVector dgCMatrix_colLogSumExps(S4 matrix, bool na_rm){
  return reduce_matrix_double(matrix, na_rm, colLogSumExps());
}

class colProds {
public:
  colProds(bool na_rm_) : na_rm(na_rm_) {}
  template<class V, class R>
  double operator()(V& values, R& row_indices, int number_of_zeros) const {
    bool any_inf = std::any_of(values.begin(), values.end(), [](const double d) -> bool {
      return d == R_PosInf || d == R_NegInf;
    });
    if(na_rm){
      if(number_of_zeros > 0 && !any_inf){
        return 0.0;
      }else if(number_of_zeros > 0 && any_inf){
        return R_NaN;
      }else{
        return std::accumulate(values.begin(), values.end(), 1.0, [](double a, double b) -> double { return a * b;});
      }
    }else{
      bool any_na = is_any_na(values);
      if(any_na){
        return NA_REAL;
      }else{
        if(number_of_zeros > 0 && !any_inf){
          return 0.0;
        }else if(number_of_zeros > 0 && any_inf){
          return R_NaN;
        }else{
          return std::accumulate(values.begin(), values.end(), 1.0, [](double a, double b) { return a * b; });
        }
      }
    }
  }
private:
  bool na_rm;
};

// [[Rcpp::export]]
NumericVector dgCMatrix_colProds(S4 matrix, bool na_rm){
  return reduce_matrix_double(matrix, na_rm, colProds(na_rm));
}



/*---------------Weighted Aggregation Functions---------------*/


template<typename Iterator, typename RIIterator>
inline double sp_weighted_mean(Iterator values, int number_of_zeros, NumericVector weights, RIIterator row_indices, double total_weights, bool na_rm){
  LDOUBLE accum = 0.0;
  double remaining_weights = total_weights;
  auto val_it = values.begin();
  auto val_end = values.end();
  auto ind_it = row_indices.begin();
  auto ind_end = row_indices.end();
  while(val_it != val_end && ind_it != ind_end){
    double v = *val_it;
    double w = weights[*ind_it];
    if(NumericVector::is_na(v)){
      if(! na_rm){
        return NA_REAL;
      }
      remaining_weights -=  w;
    }else{
      accum += v * w;
    }
    ++val_it;
    ++ind_it;
  }
  if(NumericVector::is_na(accum)){
    return accum;
  }else if(remaining_weights < 1e-9){
    return R_NaN;
  }else{
    return accum / remaining_weights;
  }
}

template<typename Iterator, typename RIIterator>
inline double sp_weighted_mean(Iterator values, int number_of_zeros, NumericVector weights, RIIterator row_indices, bool na_rm){
  return sp_weighted_mean(values, number_of_zeros, weights, sum(weights), na_rm);
}


class colWeightedMeans {
public:
  colWeightedMeans(NumericVector weights_, double total_weights_, bool na_rm_) :
  weights(weights_),
  total_weights(total_weights_),
  na_rm(na_rm_) {}
  template<class V, class R>
  double operator()(V& values, R& row_indices, int number_of_zeros) const {
    return sp_weighted_mean(values, number_of_zeros, weights, row_indices, total_weights, na_rm);
  }
private:
  NumericVector weights;
  double total_weights;
  bool na_rm;
};

// [[Rcpp::export]]
NumericVector dgCMatrix_colWeightedMeans(S4 matrix, NumericVector weights, bool na_rm){
  double total_weights = sum(weights);
  return reduce_matrix_double(matrix, false, colWeightedMeans(weights, total_weights, na_rm));
}

class colWeightedVars {
public:
  colWeightedVars(NumericVector weights_, double total_weights_, bool na_rm_) :
  weights(weights_),
  total_weights(total_weights_),
  na_rm(na_rm_) {}
  template<class V, class R>
  double operator()(V& values, R& row_indices, int number_of_zeros) const {
    double mean = sp_weighted_mean(values, number_of_zeros, weights, row_indices, total_weights, na_rm);
    if(ISNA(mean)){
      return NA_REAL;
    }

    LDOUBLE sigma2 = 0.0;
    LDOUBLE remaining_weights = total_weights;
    LDOUBLE zero_weights = total_weights;
    auto val_it = values.begin();
    auto val_end = values.end();
    auto ind_it = row_indices.begin();
    auto ind_end = row_indices.end();
    while(val_it != val_end && ind_it != ind_end){
      double v = *val_it;
      double w = weights[*ind_it];
      zero_weights -= w;
      if(NumericVector::is_na(v)){
        remaining_weights -= w;
      }else{
        double diff = mean - v;
        sigma2 += diff * diff * w;
      }
      ++val_it;
      ++ind_it;
    }
    if(number_of_zeros > 0){
      sigma2 += std::abs(zero_weights) * mean * mean;
    }
    if(NumericVector::is_na(sigma2)){
      return NA_REAL;
    }else if(remaining_weights <= 1){
      return NA_REAL;    // Yes, var(3) actually returns NA instead of NaN
    }else{
      return sigma2  / (remaining_weights - 1);
    }
  }
private:
  NumericVector weights;
  double total_weights;
  bool na_rm;
};

// [[Rcpp::export]]
NumericVector dgCMatrix_colWeightedVars(S4 matrix, NumericVector weights, bool na_rm){
  double total_weights = sum(weights);
  return reduce_matrix_double(matrix, false, colWeightedVars(weights, total_weights, na_rm));
}


/*---------------Simple Detect Functions-----------------*/

class colCounts {
public:
  colCounts(double value_, bool na_rm_) : value(value_), na_rm(na_rm_) {}
  template<class V, class R>
  double operator()(V& values, R& row_indices, int number_of_zeros) const {
    if(na_rm){
      if(value == 0.0){
        return number_of_zeros + std::count(values.begin(), values.end(), value);
      }else {
        return std::count(values.begin(), values.end(), value);
      }
    }else{
      bool contains_na = std::any_of(values.begin(), values.end(), [](const double d) -> bool{
        return NumericVector::is_na(d);
      });
      if(! contains_na){  // No NA's in the vector
        if(value == 0.0){
          return number_of_zeros + std::count(values.begin(), values.end(), value);
        }else{
          return std::count(values.begin(), values.end(), value);
        }
      }else{
        return NA_INTEGER;
      }
    }
  }
private:
  double value;
  bool na_rm;
};


// [[Rcpp::export]]
IntegerVector dgCMatrix_colCounts(S4 matrix, double value, bool na_rm){
  return reduce_matrix_int(matrix, na_rm, colCounts(value, na_rm));
}


class colAnyNAs {
public:
  colAnyNAs() {}
  template<class V, class R>
  double operator()(V& values, R& row_indices, int number_of_zeros) const {
    return is_any_na(values);
  }
};

// [[Rcpp::export]]
LogicalVector dgCMatrix_colAnyNAs(S4 matrix){
  return reduce_matrix_lgl(matrix, false, colAnyNAs());
}


class colAnys {
public:
  colAnys(double value_, bool na_rm_) : value(value_), na_rm(na_rm_) {}
  template<class V, class R>
  double operator()(V& values, R& row_indices, int number_of_zeros) const {
    if(na_rm){
      if(value == 0.0){
        return number_of_zeros > 0 || std::any_of(values.begin(), values.end(),  [this](const double d) -> bool{
          return d == value;
        });
      }else{
        return std::any_of(values.begin(), values.end(),  [this](const double d) -> bool{
          return d == value;
        });
      }
    }else{
      // !na_rm and value != 0
      bool any_na = is_any_na(values);
      bool found_value = false;
      if(value == 0.0){
        found_value = number_of_zeros > 0 || std::any_of(values.begin(), values.end(),  [this](const double d) -> bool{
          return d == value;
        });
      }else{
        found_value = std::any_of(values.begin(), values.end(),  [this](const double d) -> bool{
          return d == value;
        });
      }
      if(any_na){
        if(found_value){
          return true;
        }else{
          return NA_LOGICAL;
        }
      }else{
        return found_value;
      }
    }
  }
private:
  double value;
  bool na_rm;
};

// [[Rcpp::export]]
LogicalVector dgCMatrix_colAnys(S4 matrix, double value, bool na_rm){
  return reduce_matrix_lgl(matrix, na_rm, colAnys(value, na_rm));
}


class colAlls {
public:
  colAlls(double value_, bool na_rm_) :
  value(value_),
  na_rm(na_rm_) {}

  template<class V, class R>
  double operator()(V& values, R& row_indices, int number_of_zeros) const {
    if(value != 0.0 && number_of_zeros > 0){
      return false;
    }

    if(na_rm){
      return std::all_of(values.begin(), values.end(), [this](const double d) -> bool {
        return d == value;
      });
    }else{
      bool all_equal_or_na = std::all_of(values.begin(), values.end(), [this](const double d) -> bool {
        return d == value || NumericVector::is_na(d);
      });
      bool any_na = is_any_na(values);
      if(! all_equal_or_na){
        return false;
      }else if(all_equal_or_na && any_na){
        return NA_LOGICAL;
      }else if(all_equal_or_na && !any_na){
        return true;
      }
    }
    return false;
  }
private:
  double value;
  bool na_rm;
};


// [[Rcpp::export]]
LogicalVector dgCMatrix_colAlls(S4 matrix, double value, bool na_rm){
  Rcpp::IntegerVector dim = matrix.slot("Dim");
  return reduce_matrix_lgl(matrix, na_rm, colAlls(value, na_rm));
}


/*---------------Return matrix functions-----------------*/


class colQuantiles {
public:
  colQuantiles(NumericVector probs_, bool na_rm_) : probs(probs_), na_rm(na_rm_) {}
  template<class V, class R>
  std::vector<double> operator()(V& values, R& row_indices, int number_of_zeros) const {
    if(! na_rm){
      bool any_na = is_any_na(values);
      if(any_na){
        std::vector<double> result(probs.size(), NA_REAL);
        return result;
      }
    }
    if(values.size() + number_of_zeros == 0){
      std::vector<double> result(probs.size(), NA_REAL);
      return result;
    }
    std::vector<double> result;
    result.reserve(probs.size());
    std::transform(probs.begin(), probs.end(), back_inserter(result), [values, number_of_zeros](double prob) -> double{
      return quantile_sparse_impl(values, number_of_zeros, prob);
    });
    return result;
  }
private:
  NumericVector probs;
  bool na_rm;
};

// [[Rcpp::export]]
NumericMatrix dgCMatrix_colQuantiles(S4 matrix, NumericVector probs, bool na_rm){
  return reduce_matrix_num_matrix(matrix, na_rm, probs.size(), true, colQuantiles(probs, na_rm));
}


class colTabulate {
public:
  colTabulate(std::map<double,int>& lookup_map_, bool count_zeros_, int zero_indx_, bool count_nas_, int na_indx_) :
  lookup_map(lookup_map_),
  count_zeros(count_zeros_),
  zero_indx(zero_indx_),
  count_nas(count_nas_),
  na_indx(na_indx_) {}
  template<class V, class R>
  std::vector<int> operator()(V& values, R& row_indices, int number_of_zeros) const {
    std::vector<int> result(lookup_map.size() + count_nas + count_zeros, 0);
    int na_count = 0;
    int zero_count = 0;
    auto lookup_map_end = lookup_map.end();
    for(double v: values){
      if(Rcpp::NumericVector::is_na(v)){
        ++na_count;
      }else if(v == 0){
        ++zero_count;
      }else{
        auto search = lookup_map.find(v);
        if(search != lookup_map_end){
          result[search->second] += 1;
        }
      }
    }
    if(count_zeros){
      result[zero_indx] = zero_count + number_of_zeros;
    }
    if(count_nas){
      result[na_indx] = na_count;
    }
    return result;
  }
private:
  std::map<double,int>& lookup_map;
  bool count_zeros;
  int zero_indx;
  bool count_nas;
  int na_indx;
};


// [[Rcpp::export]]
IntegerMatrix dgCMatrix_colTabulate(S4 matrix, NumericVector sorted_unique_values){
  // std::set<int> unique_elements(values.begin(), values.end());
  // unique_elements.insert(0);
  // std::vector<int> sorted_elements;
  // std::copy(unique_elements.begin(), unique_elements.end(), std::back_inserter(sorted_elements));
  // sort(sorted_elements.begin(),sorted_elements.end(),[](int i1, int i2){
  //   if(Rcpp::IntegerVector::is_na(i1)) return false;
  //   if(Rcpp::IntegerVector::is_na(i2)) return true;
  //   return i1 < i2;
  // });
  std::map<double,int> lookup_map;
  bool count_nas = false;
  bool count_zeros = false;
  int zero_indx = -1;
  int na_indx = -1;
  for(int i = 0; i < sorted_unique_values.size(); ++i){
    double value = sorted_unique_values[i];
    if(Rcpp::NumericVector::is_na(value)){
      count_nas = true;
      na_indx = i;
    }else if(value == 0){
      count_zeros = true;
      zero_indx = i;
    }else{
      lookup_map[value] = i;
    }
  }
  return reduce_matrix_int_matrix_with_na(matrix, lookup_map.size() + count_nas + count_zeros, true,
                                          colTabulate(lookup_map, count_zeros, zero_indx, count_nas, na_indx));
}



/*---------------Cumulative functions-----------------*/

class colCumsums {
public:
  colCumsums(R_len_t nrows_) : nrows(nrows_) {}
  template<class V, class R>
  std::vector<double> operator()(V& values, R& row_indices, int number_of_zeros) const {
    std::vector<double> result(nrows);
    double acc = 0;
    auto row_it = row_indices.begin();
    auto row_end = row_indices.end();
    auto val_it = values.begin();
    auto res_it = result.begin();
    for(int i = 0; i < nrows; ++i, ++res_it){
      if(row_it != row_end && i == *row_it){
        acc += *val_it;
        ++row_it;
        ++val_it;
      }
      *res_it = acc;
    }
    return result;
  }
private:
  R_len_t nrows;
};

// [[Rcpp::export]]
NumericMatrix dgCMatrix_colCumsums(S4 matrix){
  Rcpp::IntegerVector dim = matrix.slot("Dim");
  R_len_t nrows = dim[0];
  return reduce_matrix_num_matrix_with_na(matrix, nrows, false, colCumsums(nrows));
}



class colCumprods {
public:
  colCumprods(R_len_t nrows_) : nrows(nrows_) {}
  template<class V, class R>
  std::vector<double> operator()(V& values, R& row_indices, int number_of_zeros) const {
    std::vector<double> result(nrows);
    LDOUBLE acc = 1;
    auto row_it = row_indices.begin();
    auto row_end = row_indices.end();
    auto val_it = values.begin();
    auto res_it = result.begin();
    for(int i = 0; i < nrows; ++i, ++res_it){
      if(row_it != row_end && i == *row_it){
        acc *= *val_it;
        ++row_it;
        ++val_it;
      }else{
        acc = 0 * acc;
      }
      *res_it = acc;
    }
    return result;
  }
private:
  R_len_t nrows;
};

// [[Rcpp::export]]
NumericMatrix dgCMatrix_colCumprods(S4 matrix){
  Rcpp::IntegerVector dim = matrix.slot("Dim");
  R_len_t nrows = dim[0];
  return reduce_matrix_num_matrix_with_na(matrix, nrows, false, colCumprods(nrows));
}


class colCummins {
public:
  colCummins(R_len_t nrows_) : nrows(nrows_) {}
  template<class V, class R>
  std::vector<double> operator()(V& values, R& row_indices, int number_of_zeros) const {
    std::vector<double> result(nrows);
    if(nrows == 0){
      // Without this escape hatch, the following code would segfault
      return result;
    }
    auto row_it = row_indices.begin();
    auto row_end = row_indices.end();
    auto val_it = values.begin();
    auto res_it = result.begin();
    int i = 0;
    double acc = 0.0;
    if(row_it != row_end && i == *row_it){
      acc = *val_it;
      ++row_it;
      ++val_it;
    }else{
      acc = 0.0;
    }
    *res_it = acc;
    ++res_it;
    for(i = 1; i < nrows; ++i, ++res_it){
      if(NumericVector::is_na(acc)){
        // Do nothing it will always stay NA
      }else if(row_it != row_end && i == *row_it){
        acc = std::min(*val_it, acc);
        ++row_it;
        ++val_it;
      }else{
        acc = std::min(0.0, acc);
      }
      *res_it = acc;
    }
    return result;
  }
private:
  R_len_t nrows;
};

// [[Rcpp::export]]
NumericMatrix dgCMatrix_colCummins(S4 matrix){
  Rcpp::IntegerVector dim = matrix.slot("Dim");
  R_len_t nrows = dim[0];
  return reduce_matrix_num_matrix_with_na(matrix, nrows, false, colCummins(nrows));
}


class colCummaxs {
public:
  colCummaxs(R_len_t nrows_) : nrows(nrows_) {}
  template<class V, class R>
  std::vector<double> operator()(V& values, R& row_indices, int number_of_zeros) const {
    std::vector<double> result(nrows);
    if(nrows == 0){
      // Without this escape hatch, the following code would segfault
      return result;
    }
    auto row_it = row_indices.begin();
    auto row_end = row_indices.end();
    auto val_it = values.begin();
    auto res_it = result.begin();
    int i = 0;
    double acc = 0.0;
    if(row_it != row_end && i == *row_it){
      acc = *val_it;
      ++row_it;
      ++val_it;
    }else{
      acc = 0.0;
    }
    *res_it = acc;
    ++res_it;
    for(i = 1; i < nrows; ++i, ++res_it){
      if(NumericVector::is_na(acc)){
        // Do nothing it will always stay NA
      }else if(row_it != row_end && i == *row_it){
        acc = std::max(*val_it, acc);
        ++row_it;
        ++val_it;
      }else{
        acc = std::max(0.0, acc);
      }
      *res_it = acc;
    }
    return result;
  }
private:
  R_len_t nrows;
};

// [[Rcpp::export]]
NumericMatrix dgCMatrix_colCummaxs(S4 matrix){
  Rcpp::IntegerVector dim = matrix.slot("Dim");
  R_len_t nrows = dim[0];
  return reduce_matrix_num_matrix_with_na(matrix, nrows, false, colCummaxs(nrows));
}


/*------------------Ranking function------------------*/

class colRanks_num {
public:
  colRanks_num(std::string na_handling_, std::string ties_method_) :
  na_handling(na_handling_),
  ties_method(ties_method_) {}

  std::vector<double> operator()(VectorSubsetView<REALSXP>  values, VectorSubsetView<INTSXP>  row_indices, int number_of_zeros) const {
    return calculate_sparse_rank<double>(values, row_indices, number_of_zeros, ties_method, na_handling);
  }

private:
  std::string na_handling;
  std::string ties_method;
};

// [[Rcpp::export]]
NumericMatrix dgCMatrix_colRanks_num(S4 matrix, std::string ties_method, std::string na_handling, bool preserve_shape){
  Rcpp::IntegerVector dim = matrix.slot("Dim");
  R_len_t nrows = dim[0];
  return reduce_matrix_num_matrix_with_na(matrix, nrows, !preserve_shape,
                                          colRanks_num(na_handling, ties_method));
}


class colRanks_int {
public:
  colRanks_int(std::string na_handling_, std::string ties_method_) :
  na_handling(na_handling_),
  ties_method(ties_method_) {}

  std::vector<int> operator()(VectorSubsetView<REALSXP> values, VectorSubsetView<INTSXP> row_indices, int number_of_zeros) const {
    return calculate_sparse_rank<int>(values, row_indices, number_of_zeros, ties_method, na_handling);
  }

private:
  std::string na_handling;
  std::string ties_method;
};

// [[Rcpp::export]]
IntegerMatrix dgCMatrix_colRanks_int(S4 matrix, std::string ties_method, std::string na_handling, bool preserve_shape){
  Rcpp::IntegerVector dim = matrix.slot("Dim");
  R_len_t nrows = dim[0];
  return reduce_matrix_int_matrix_with_na(matrix, nrows, !preserve_shape,
                                          colRanks_int(na_handling, ties_method));
}






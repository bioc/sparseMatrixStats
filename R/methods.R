

# Sum

#' @inherit MatrixGenerics::colSums2
#' @export
setMethod("colSums2", signature(x = "xgCMatrix"), function(x, rows = NULL, cols = NULL, na.rm=FALSE, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  set_result_names(dgCMatrix_colSums2(x, na_rm = na.rm), useNames)
})


# Mean

#' @inherit MatrixGenerics::colMeans2
#' @export
setMethod("colMeans2", signature(x = "xgCMatrix"),
          function(x, rows = NULL, cols = NULL, na.rm=FALSE, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  set_result_names(dgCMatrix_colMeans2(x, na_rm = na.rm), useNames)
})


# Median

#' @inherit MatrixGenerics::colMedians
#' @export
setMethod("colMedians", signature(x = "dgCMatrix"),
          function(x, rows = NULL, cols = NULL, na.rm=FALSE, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  set_result_names(dgCMatrix_colMedians(x, na_rm = na.rm), useNames)
})


# Vars

#' @inherit MatrixGenerics::colVars
#' @export
setMethod("colVars", signature(x = "xgCMatrix"),
          function(x, rows = NULL, cols = NULL, na.rm=FALSE, center = NULL, useNames = TRUE){
  if(! is.null(center) && length(center) != ncol(x)){
    stop("Argument 'center' must be the same length as number of columns of 'x': ", length(center), "!=", ncol(x))
  }
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  set_result_names(dgCMatrix_colVars(x, na_rm = na.rm, center = center), useNames, default = nrow(x) > 0 && !is.null(center))
})


# Sds

#' @inherit MatrixGenerics::colSds
#' @export
setMethod("colSds", signature(x = "xgCMatrix"),
          function(x, rows = NULL, cols = NULL, na.rm=FALSE, center = NULL, useNames = TRUE){
  if(! is.null(center) && length(center) != ncol(x)){
    stop("Argument 'center' must be the same length as number of columns of 'x': ", length(center), "!=", ncol(x))
  }
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  set_result_names(sqrt(dgCMatrix_colVars(x, na_rm = na.rm, center = center)), useNames, default =  nrow(x) > 0 && !is.null(center))
})


# Mads

#' @inherit MatrixGenerics::colMads
#' @export
setMethod("colMads", signature(x = "dgCMatrix"),
          function(x, rows = NULL, cols = NULL, center = NULL, constant = 1.4826, na.rm=FALSE, useNames = TRUE){
  if(! is.null(center) && length(center) != ncol(x)){
    stop("Argument 'center' must be the same length as number of columns of 'x': ", length(center), "!=", ncol(x))
  }
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  set_result_names(dgCMatrix_colMads(x, na_rm = na.rm, scale_factor = constant, center = center), useNames)
})


# LogSumExp

#' @inherit MatrixGenerics::colLogSumExps
#' @export
setMethod("colLogSumExps", signature(lx = "xgCMatrix"),
          function(lx, rows = NULL, cols = NULL, na.rm=FALSE, useNames = TRUE){
  if(! is.null(rows)){
    lx <- lx[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    lx <- lx[, cols, drop = FALSE]
  }
  set_result_names(dgCMatrix_colLogSumExps(lx, na_rm = na.rm), useNames, default = TRUE, names = colnames(lx))
})


# Prods

#' Calculates the product for each row (column) in a matrix
#'
#' Calculates the product for each row (column) in a matrix
#'
#'
#' Attention: This method ignores the order of the values, because it assumes that
#' the product is commutative. Unfortunately, for 'double' this is not true.
#' For example `NaN * NA = NaN`, but `NA * NaN = NA`. This is relevant for this
#' function if there are `+-Inf`, because `Inf * 0 = NaN`. This function returns
#' `NA` whenever there is `NA` in the input. This is different from `matrixStats::colProds()`.
#'
#' @seealso
#' \itemize{
#'   \item \code{matrixStats::\link[matrixStats]{rowProds}()} and
#'     \code{matrixStats::\link[matrixStats:rowProds]{colProds}()} which are used
#'     when the input is a \code{matrix} or \code{numeric} vector.
#'   \item For sums across rows (columns), see
#'     \code{rowSums2()} (\code{colSums2()})
#'   \item \code{base::\link{prod}()}.
#' }
#'
#' @inherit MatrixGenerics::colProds
#'
#' @export
setMethod("colProds", signature(x = "xgCMatrix"),
          function(x, rows = NULL, cols = NULL, na.rm=FALSE, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  set_result_names(dgCMatrix_colProds(x, na_rm = na.rm), useNames)
})



# Min

#' @inherit MatrixGenerics::colMins
#' @export
setMethod("colMins", signature(x = "dgCMatrix"),
          function(x, rows = NULL, cols = NULL, na.rm=FALSE, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  set_result_names(dgCMatrix_colMins(x, na_rm = na.rm), useNames)
})


# Max

#' @inherit MatrixGenerics::colMaxs
#' @export
setMethod("colMaxs", signature(x = "dgCMatrix"),
          function(x, rows = NULL, cols = NULL, na.rm=FALSE, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  set_result_names(dgCMatrix_colMaxs(x, na_rm = na.rm), useNames)
})


# OrderStats

#' @inherit MatrixGenerics::colOrderStats
#' @param na.rm If TRUE, NAs are excluded first, otherwise not.
#'
#' @export
setMethod("colOrderStats", signature(x = "dgCMatrix"),
          function(x, rows = NULL, cols = NULL, which = 1, na.rm=FALSE, useNames = TRUE){
  if(which < 1 || which > nrow(x)){
    stop("Argument 'which' is out of range.")
  }
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  set_result_names(dgCMatrix_colOrderStats(x, which = which, na_rm = na.rm), useNames)
})




# Weighted Means

#' @inherit MatrixGenerics::colWeightedMeans
#' @export
setMethod("colWeightedMeans", signature(x = "xgCMatrix"),
          function(x, w = NULL, rows = NULL, cols = NULL, na.rm=FALSE, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
    w <- w[rows]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }

  if(is.null(w)){
    set_result_names(dgCMatrix_colMeans2(x, na_rm = na.rm), useNames, default = TRUE)
  }else{
    if(length(w) != nrow(x)){
      stop("The number of elements in arguments 'w'and 'x' does not match: ",
           length(w), " != ", nrow(x))
    }
    set_result_names(dgCMatrix_colWeightedMeans(x, weights = w, na_rm = na.rm), useNames, default = nrow(x) > 0)
  }
})



# Weighted Medians

#' @inherit MatrixGenerics::colWeightedMedians
#' @export
setMethod("colWeightedMedians", signature(x = "dgCMatrix"),
          function(x, w = NULL, rows = NULL, cols = NULL, na.rm=FALSE, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
    w <- w[rows]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }

  if(is.null(w)){
    set_result_names(dgCMatrix_colMedians(x, na_rm = na.rm), useNames)
  }else{
    if(length(w) != nrow(x)){
      stop("The number of elements in arguments 'w'and 'x' does not match: ",
           length(w), " != ", nrow(x))
    }
    set_result_names(reduce_sparse_matrix_to_num(x, function(values, row_indices, number_of_zeros){
      if(length(values) == 0 && number_of_zeros > 0){
        return(0.0)
      }else if(length(values) == 0 && number_of_zeros > 0){
        return(NA)
      }else{
        new_vec <- c(0, values)
        zero_weight <- sum(w[-(row_indices + 1)])
        new_weights <- c(zero_weight, w[row_indices + 1])
        matrixStats::weightedMedian(new_vec, new_weights, na.rm=na.rm, interpolate = FALSE)
      }
    }), useNames, default = TRUE)
  }
})


# Weighted Vars

#' @inherit MatrixGenerics::colWeightedVars
#' @export
setMethod("colWeightedVars", signature(x = "xgCMatrix"),
          function(x, w = NULL, rows = NULL, cols = NULL, na.rm=FALSE, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
    w <- w[rows]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }

  if(is.null(w)){
    set_result_names(dgCMatrix_colVars(x, na_rm = na.rm, center = NULL), useNames, default = TRUE)
  }else{
    if(length(w) != nrow(x)){
      stop("The number of elements in arguments 'w'and 'x' does not match: ",
           length(w), " != ", nrow(x))
    }
    set_result_names(dgCMatrix_colWeightedVars(x, weights = w, na_rm = na.rm), useNames, default = TRUE)
  }
})



# Weighted Sds

#' @inherit MatrixGenerics::colWeightedSds
#' @export
setMethod("colWeightedSds", signature(x = "xgCMatrix"),
          function(x, w = NULL, rows = NULL, cols = NULL, na.rm=FALSE, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
    w <- w[rows]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }

  if(is.null(w)){
    set_result_names(sqrt(dgCMatrix_colVars(x, na_rm = na.rm, center = NULL)), useNames, default = TRUE)
  }else{
    if(length(w) != nrow(x)){
      stop("The number of elements in arguments 'w'and 'x' does not match: ",
           length(w), " != ", nrow(x))
    }
    set_result_names(sqrt(dgCMatrix_colWeightedVars(x, weights = w, na_rm = na.rm)), useNames, default = TRUE)
  }
})



# Weighted Mads

#' @inherit MatrixGenerics::colWeightedMads
#' @param center Not supported at the moment.
#'
#' @examples
#'   mat <- matrix(0, nrow=10, ncol=5)
#'   mat[sample(prod(dim(mat)), 25)] <- rpois(n=25, 5)
#'   sp_mat <- as(mat, "dgCMatrix")
#'   weights <- rnorm(10, mean=1, sd=0.1)
#'
#'   # sparse version
#'   sparseMatrixStats::colWeightedMads(sp_mat, weights)
#'
#'   # Attention the result differs from matrixStats
#'   # because it always uses 'interpolate=FALSE'.
#'   matrixStats::colWeightedMads(mat, weights)
#'
#' @export
setMethod("colWeightedMads", signature(x = "dgCMatrix"),
          function(x, w = NULL, rows = NULL, cols = NULL, na.rm=FALSE, constant = 1.4826, center = NULL, useNames = TRUE){
  if(! is.null(center)) stop("colWeightedMads does not support the 'center' argument.")
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
    w <- w[rows]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  if(is.null(w)){
    set_result_names(dgCMatrix_colMads(x, na_rm = na.rm, scale_factor = constant, center = center), useNames, default = TRUE)
  }else{
    if(length(w) != nrow(x)){
      stop("The number of elements in arguments 'w'and 'x' does not match: ",
           length(w), " != ", nrow(x))
    }
    set_result_names(reduce_sparse_matrix_to_num(x, function(values, row_indices, number_of_zeros){
      if(length(values) == 0){
        if(number_of_zeros > 0){
          0
        }else{
          NA_real_
        }
      }else{
        new_vec <- c(0, values)
        zero_weight <- sum(w[-(row_indices + 1)])
        new_weights <- c(zero_weight, w[row_indices + 1])
        center <- matrixStats::weightedMedian(new_vec, new_weights, na.rm=na.rm, interpolate = FALSE)
        if(is.infinite(center)){
          # One of values must be Inf, thus Inf - Inf = NaN --> whole result is unknowable
          # Danger of na.rm: removes NaN as well
          return(NA)
        }
        x <- abs(new_vec - center)
        sigma <- matrixStats::weightedMedian(x, w = new_weights, na.rm = na.rm, interpolate = FALSE)
        # Rescale for normal distributions
        sigma <- constant * sigma
        sigma
      }
    }), useNames, default = TRUE)
  }
})



# Count

#' @inherit MatrixGenerics::colCounts
#' @export
setMethod("colCounts", signature(x = "xgCMatrix"),
          function(x, rows = NULL, cols = NULL, value = TRUE, na.rm=FALSE, useNames = TRUE){
  stopifnot(length(value) == 1)
  if(is(x, "lgCMatrix")){
    value <- as.logical(value)
  }
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  set_result_names(dgCMatrix_colCounts(x, value, na_rm = na.rm), useNames)
})


# AnyNA

#' @inherit MatrixGenerics::colAnyNAs
#'
#' @examples
#'   mat <- matrix(0, nrow=10, ncol=5)
#'   mat[sample(seq_len(5 *10), 5)] <- NA
#'   sp_mat <- as(mat, "dgCMatrix")
#'   colAnyNAs(sp_mat)
#'
#' @export
setMethod("colAnyNAs", signature(x = "xgCMatrix"),
          function(x, rows = NULL, cols = NULL, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  set_result_names(dgCMatrix_colAnyNAs(x), useNames)
})


# Anys

#' @inherit MatrixGenerics::colAnys
#' @export
setMethod("colAnys", signature(x = "xgCMatrix"),
          function(x, rows = NULL, cols = NULL, value = TRUE, na.rm=FALSE, useNames = TRUE){
  stopifnot(length(value) == 1)
  if(is(x, "lgCMatrix")){
    value <- as.logical(value)
  }
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  res <- if(isTRUE(value)){
    ! dgCMatrix_colAlls(x, value = 0, na_rm=na.rm)
  }else{
    dgCMatrix_colAnys(x, value, na_rm=na.rm)
  }
  set_result_names(res, useNames)
})



# Alls

#' @inherit MatrixGenerics::colAlls
#' @export
setMethod("colAlls", signature(x = "xgCMatrix"),
          function(x, rows = NULL, cols = NULL, value = TRUE, na.rm=FALSE, useNames = TRUE){
  stopifnot(length(value) == 1)
  if(is(x, "lgCMatrix")){
    value <- as.logical(value)
  }
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  res <- if(isTRUE(value)){
    ! dgCMatrix_colAnys(x, value = 0, na_rm = na.rm)
  }else{
    dgCMatrix_colAlls(x, value, na_rm=na.rm)
  }
  set_result_names(res, useNames)
})



# Collapse

#' @inherit MatrixGenerics::colCollapse
#' @export
setMethod("colCollapse", signature(x = "xgCMatrix"),
          function(x, idxs, cols = NULL, useNames = TRUE){
  idxs <- rep(idxs, length.out = ncol(x))
  if (!is.null(cols)) {
    x <- x[, cols, drop = FALSE]
    idxs <- idxs[cols]
  }
  rows <- seq_len(nrow(x))
  rows <- rows[idxs]
  idxs <- nrow(x) * (seq_len(ncol(x)) - 1L) + rows
  rows <- NULL
  set_result_names(x[idxs], useNames)
})




# colQuantiles

#' @inherit MatrixGenerics::colQuantiles
#' @export
setMethod("colQuantiles", signature(x = "xgCMatrix"),
          function(x, rows = NULL, cols = NULL, probs = seq(from = 0, to = 1, by = 0.25), na.rm=FALSE, type = 7L, useNames = TRUE, drop = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  if(type == 7L){
    mat <- dgCMatrix_colQuantiles(x, probs, na_rm = na.rm)
  }else{
    mat <- t(expand_and_reduce_sparse_matrix_to_matrix(x, n_result_rows = length(probs), function(values){
      if(na.rm){
        values <- values[!is.na(values)]
        stats::quantile(values, probs = probs, na.rm = na.rm, names = FALSE, type = type)
      }else if(any(is.na(values))){
        r <- rep(NA_real_, length(probs))
        storage.mode(r) <- typeof(values)
        r
      }else{
        stats::quantile(values, probs = probs, na.rm = na.rm, names = FALSE, type = type)
      }
    }))
  }
  # Add dim names
  digits <- max(2L, getOption("digits"))
  mat <- set_result_colnames(mat, useNames, default = TRUE, names = sprintf("%.*g%%", digits, 100 * probs))
  mat <- set_result_rownames(mat, useNames, default = TRUE)
  if(drop && nrow(mat) == 1){
    mat[1,]
  }else  if(drop && ncol(mat) == 1){
    mat[,1]
  }else{
    mat
  }
})



# colTabulates

#' @inherit MatrixGenerics::colTabulates
#' @export
setMethod("colTabulates", signature(x = "xgCMatrix"),
          function(x, rows = NULL, cols = NULL, values = NULL, useNames = TRUE){
  if(is(x, "lgCMatrix")){
    if(! is.null(values)){
      values <- as.logical(values)
    }
    default_value <- FALSE
  }else{
    default_value <- 0
  }
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  if(is.null(values)){
    recheck_that_zeros_in_matrix <- TRUE
    repeat_duplicate_values <- FALSE
    values <- c(x@x, default_value)
    unique_values <- sort(unique(values), na.last = TRUE)
  }else{
    recheck_that_zeros_in_matrix <- FALSE
    repeat_duplicate_values <- TRUE
    unique_values <- unique(values)
  }
  mat <- dgCMatrix_colTabulate(x, unique_values)
  # Add dim names
  colnames(mat) <- ifelse(is.na(unique_values), "NA", unique_values)
  mat <- set_result_rownames(mat, useNames, default = TRUE)
  if(recheck_that_zeros_in_matrix && all(mat[, as.character(default_value)] == 0)){
    # Remove zero column is there is not a single zero in x
    mat <- mat[, -which(colnames(mat) == as.character(default_value)), drop=FALSE]
  }
  if(repeat_duplicate_values){
    mat <- mat[,  ifelse(is.na(values), "NA", as.character(values)), drop=FALSE]
  }
  colnames(mat) <- ifelse(colnames(mat) == "NA", NA, colnames(mat))
  mat
})



# colIQRs

#' @inherit MatrixGenerics::colIQRs
#' @export
setMethod("colIQRs", signature(x = "xgCMatrix"),
          function(x, rows = NULL, cols = NULL, na.rm=FALSE, useNames = TRUE){
  col_q <- colQuantiles(x, rows, cols, probs=c(0.25, 0.75), na.rm = na.rm, useNames = TRUE, drop = FALSE)
  if(is.na(useNames)){
    useNames <- FALSE
  }
  set_result_names(unname(col_q[,2] - col_q[,1]), useNames, names = rownames(col_q))
})



# colRanges

#' @inherit MatrixGenerics::colRanges
#' @export
setMethod("colRanges", signature(x = "dgCMatrix"),
          function(x, rows = NULL, cols = NULL, na.rm=FALSE, useNames = TRUE){
  col_max <- colMaxs(x, rows, cols, na.rm = na.rm, useNames = TRUE)
  col_min <- colMins(x, rows, cols, na.rm = na.rm, useNames = TRUE)
  if(is.na(useNames)){
    useNames <- FALSE
  }
  set_result_rownames(unname(cbind(col_min, col_max)), useNames, names = names(col_max))
})



# colCumsums

#' @inherit MatrixGenerics::colCumsums
#' @export
setMethod("colCumsums", signature(x = "xgCMatrix"),
          function(x, rows = NULL, cols = NULL, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  mat <- dgCMatrix_colCumsums(x)
  mat <- set_result_colnames(mat, useNames)
  mat <- set_result_rownames(mat, useNames, names = rownames(x))
  mat
})



# colCumprods

#' @inherit MatrixGenerics::colCumprods
#' @export
setMethod("colCumprods", signature(x = "xgCMatrix"),
          function(x, rows = NULL, cols = NULL, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  mat <- dgCMatrix_colCumprods(x)
  mat <- set_result_colnames(mat, useNames)
  mat <- set_result_rownames(mat, useNames, names = rownames(x))
  mat
})



# colCummins

#' @inherit MatrixGenerics::colCummins
#' @export
setMethod("colCummins", signature(x = "dgCMatrix"),
          function(x, rows = NULL, cols = NULL, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  mat <- dgCMatrix_colCummins(x)
  mat <- set_result_colnames(mat, useNames)
  mat <- set_result_rownames(mat, useNames, names = rownames(x))
  mat
})



# colCummaxs

#' @inherit MatrixGenerics::colCummaxs
#' @export
setMethod("colCummaxs", signature(x = "dgCMatrix"),
          function(x, rows = NULL, cols = NULL, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  mat <- dgCMatrix_colCummaxs(x)
  mat <- set_result_colnames(mat, useNames)
  mat <- set_result_rownames(mat, useNames, names = rownames(x))
  mat
})




# colRanks

#' @inherit MatrixGenerics::colRanks
#' @param preserveShape a boolean that specifies if the returned matrix has the same
#'   dimensions as the input matrix. By default this is true for `rowRanks()`, but false for
#'   `colRanks()`.
#' @param na.handling string specifying how `NA`s are handled. They can either be preserved with an `NA` rank
#'   ('keep') or sorted in at the end ('last'). Default is 'keep' derived from the behavior of the equivalent
#'
#' @details
#'    There are three different methods available for handling ties:
#'    \describe{
#'      \item{`max`}{for values with identical values the maximum rank is returned}
#'      \item{`average`}{for values with identical values the average of the ranks they cover
#'      is returned. Note, that in this case the return value is of type `numeric`.}
#'      \item{`min`}{for values with identical values the minimum rank is returned.}
#'    }
#' @export
setMethod("colRanks", signature(x = "dgCMatrix"),
          function(x, rows = NULL, cols = NULL,  ties.method = c("max", "average", "min"), preserveShape = FALSE, na.handling = c("keep", "last"), ..., useNames = TRUE){
  # For some weird reason the `...` in the signature are essential
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  ties.method <- match.arg(ties.method,  c("max", "average", "min"))
  na.handling <- match.arg(na.handling, c("keep", "last"))
  mat <- if(ties.method == "average"){
    dgCMatrix_colRanks_num(x, ties_method = ties.method, na_handling = na.handling, preserve_shape = preserveShape)
  }else{
    dgCMatrix_colRanks_int(x, ties_method = ties.method, na_handling = na.handling, preserve_shape = preserveShape)
  }
  mat <- set_result_rownames(mat, useNames, names = colnames(x))
  mat <- set_result_colnames(mat, useNames, names = rownames(x))
  mat
})



#' @inherit MatrixGenerics::colDiffs
#'
#' @export
setMethod("colDiffs", signature(x = "dgCMatrix"),
          function(x, rows = NULL, cols = NULL, lag = 1L, differences = 1L, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  if(differences == 0){
    mat <- set_result_colnames(x, useNames)
    mat <- set_result_rownames(mat, useNames, names = rownames(x))
    mat
  }else{
    mat <- reduce_sparse_matrix_to_matrix(x, n_result_rows = max(nrow(x) - differences * lag, 0), function(values, row_indices, number_of_zeros){
      tmp <- rep(0,  nrow(x))
      tmp[row_indices+1] <- values
      matrixStats::diff2(tmp, lag = lag, differences = differences)
    })
    mat <- set_result_colnames(mat, useNames, names = colnames(x))
    indices <- setdiff(seq_len(nrow(x)), seq_len(differences * lag))
    mat <- set_result_rownames(mat, useNames, names = rownames(x)[indices])
    mat
  }
})



#' @inherit MatrixGenerics::colVarDiffs
#'
#' @export
setMethod("colVarDiffs", signature(x = "dgCMatrix"),
          function(x, rows = NULL, cols = NULL, na.rm = FALSE, diff = 1L, trim = 0, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  if(diff == 0){
    set_result_names(dgCMatrix_colVars(x, na_rm = na.rm, center = NULL), useNames, default = TRUE)
  }else{
    n <- nrow(x)
    set_result_names(reduce_sparse_matrix_to_num(x, function(values, row_indices, number_of_zeros){
      tmp <- rep(0, n)
      tmp[row_indices+1] <- values
      matrixStats::varDiff(tmp, na.rm=na.rm, diff = diff, trim = trim)
    }), useNames, default = TRUE)
  }
})




#' @inherit MatrixGenerics::colSdDiffs
#'
#' @export
setMethod("colSdDiffs", signature(x = "dgCMatrix"),
          function(x, rows = NULL, cols = NULL, na.rm = FALSE, diff = 1L, trim = 0, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  if(diff == 0){
    set_result_names(sqrt(dgCMatrix_colVars(x, na_rm = na.rm, center = NULL)), useNames, default = TRUE)
  }else{
    n <- nrow(x)
    set_result_names(reduce_sparse_matrix_to_num(x, function(values, row_indices, number_of_zeros){
      tmp <- rep(0, n)
      tmp[row_indices+1] <- values
      matrixStats::sdDiff(tmp, na.rm=na.rm, diff = diff, trim = trim)
    }), useNames, default = TRUE)
  }
})



#' @inherit MatrixGenerics::colMadDiffs
#' @param constant A scale factor. See \code{\link{mad}} for details.
#' @export
setMethod("colMadDiffs", signature(x = "dgCMatrix"),
          function(x, rows = NULL, cols = NULL, na.rm = FALSE, diff = 1L, trim = 0, constant = 1.4826, ..., useNames = TRUE){
  # Here again the `...` is for some weird reason essential
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  if(diff == 0){
    set_result_names(dgCMatrix_colMads(x, na_rm = na.rm, scale_factor = constant, center = NULL), useNames, default = TRUE)
  }else{
    n <- nrow(x)
    set_result_names(reduce_sparse_matrix_to_num(x, function(values, row_indices, number_of_zeros){
      tmp <- rep(0, n)
      tmp[row_indices+1] <- values
      matrixStats::madDiff(tmp, na.rm=na.rm, diff = diff, trim = trim, constant = constant)
    }), useNames, default = TRUE)
  }
})



#' @inherit MatrixGenerics::colIQRDiffs
#'
#' @export
setMethod("colIQRDiffs", signature(x = "dgCMatrix"),
function(x, rows = NULL, cols = NULL, na.rm = FALSE, diff = 1L, trim = 0, useNames = TRUE){
  if(! is.null(rows)){
    x <- x[rows, , drop = FALSE]
  }
  if(! is.null(cols)){
    x <- x[, cols, drop = FALSE]
  }
  if(diff == 0){
    set_result_names(colIQRs(x, na.rm = na.rm), useNames, default = TRUE)
  }else{
    n <- nrow(x)
    set_result_names(reduce_sparse_matrix_to_num(x, function(values, row_indices, number_of_zeros){
      tmp <- rep(0, n)
      tmp[row_indices+1] <- values
      matrixStats::iqrDiff(tmp, na.rm=na.rm, diff = diff, trim = trim)
    }), useNames, default = TRUE)
  }
})



#' Calculates for each row (column) a summary statistic for equally sized subsets of columns (rows)
#'
#' Calculates for each row (column) a summary statistic for equally sized subsets of columns (rows)
#'
#' @inherit MatrixGenerics::colAvgsPerRowSet
#'
#'
#' @details
#'   **Note**: the handling of missing parameters differs from
#'   [matrixStats::colAvgsPerRowSet()]. The `matrixStats` version
#'   always removes `NA`'s if there are any in the data. This method
#'   however does whatever is passed in the `...` parameter.
#'
#' @aliases colAvgsPerRowSet
#' @export
setMethod("colAvgsPerRowSet", signature(X = "xgCMatrix"),
function(X, W = NULL, cols = NULL, S, FUN = colMeans2, ..., na.rm = NA, tFUN = FALSE){
  if(! is.null(W)) stop("the W parameter is not supported.")
  nbrOfSets <- ncol(S)
  setNames <- colnames(S)
  if (!is.function(FUN)) {
    stop("Argument 'FUN' is not a function: ", mode(S))
  }
  if (!is.null(cols)) {
    X <- X[, cols, drop = FALSE]
  }
  dimX <- dim(X)
  tFUN <- as.logical(tFUN)

  # Check if missing values have to be excluded while averaging
  if (is.na(na.rm)) na.rm <- (base::anyNA(X@x) || matrixStats::anyMissing(S))

  colnamesX <- colnames(X)
  dimnames(X) <- list(NULL, NULL)

  Z <- apply(S, MARGIN = 2L, FUN = function(jj) {
    jj <- jj[is.finite(jj)]
    Zjj <- X[jj, , drop = FALSE]
    jj <- NULL
    if (tFUN) {
      Zjj <- t(Zjj)
    }
    tryCatch({
      Zjj <- FUN(Zjj, ..., na.rm = na.rm)
    }, error = function(err){
      Zjj <<- FUN(as.matrix(Zjj), ..., na.rm = na.rm)
    })
    if (length(Zjj) != dimX[2L])
      stop("Internal error: length(Zjj) != dimX[1L]")
    Zjj
  })
  if (!is.matrix(Z)) {
    if (dimX[2] > 1L)
      stop("Internal error: dimX[1] > 1L")
    dim(Z) <- c(dimX[2L], nbrOfSets)
  }
  if (any(dim(Z) != c(dimX[2L], nbrOfSets)))
    stop("Internal error: dim(Z) != c(dimX[1L], nbrOfSets)")
  rownames(Z) <- colnamesX
  colnames(Z) <- setNames
  t(Z)
})


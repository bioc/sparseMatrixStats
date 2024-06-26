% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/methods.R, R/methods_row.R
\name{colOrderStats,dgCMatrix-method}
\alias{colOrderStats,dgCMatrix-method}
\alias{rowOrderStats,dgCMatrix-method}
\title{Calculates an order statistic for each row (column) of a matrix-like object}
\usage{
\S4method{colOrderStats}{dgCMatrix}(
  x,
  rows = NULL,
  cols = NULL,
  which = 1,
  na.rm = FALSE,
  useNames = TRUE
)

\S4method{rowOrderStats}{dgCMatrix}(
  x,
  rows = NULL,
  cols = NULL,
  which = 1,
  na.rm = FALSE,
  useNames = TRUE
)
}
\arguments{
\item{x}{An NxK matrix-like object.}

\item{rows, cols}{A \code{\link{vector}} indicating the subset of rows
(and/or columns) to operate over. If \code{\link{NULL}}, no subsetting is
done.}

\item{which}{An integer index in [1,K] ([1,N]) indicating which order
statistic to be returned}

\item{na.rm}{If TRUE, NAs are excluded first, otherwise not.}

\item{useNames}{If \code{\link{TRUE}} (default), names attributes of result are set. Else if \code{\link{FALSE}}, no naming support is done.}
}
\value{
Returns a \code{\link{numeric}} \code{\link{vector}} of length N (K).
}
\description{
Calculates an order statistic for each row (column) of a matrix-like object.
}
\details{
The S4 methods for \code{x} of type \code{\link{matrix}},
\code{\link{array}}, \code{\link{table}}, or \code{\link{numeric}} call
\code{matrixStats::\link[matrixStats]{rowOrderStats}} /
\code{matrixStats::\link[matrixStats]{colOrderStats}}.
}
\examples{
mat <- matrix(rnorm(15), nrow = 5, ncol = 3)
    mat[2, 1] <- 2
    mat[3, 3] <- Inf
    mat[4, 1] <- 0

    print(mat)

    rowOrderStats(mat, which = 1)
    colOrderStats(mat, which = 3)
}
\seealso{
\itemize{
\item \code{matrixStats::\link[matrixStats]{rowOrderStats}()} and
\code{matrixStats::\link[matrixStats:rowOrderStats]{colOrderStats}()}
which are used when the input is a \code{matrix} or \code{numeric} vector.
}
}

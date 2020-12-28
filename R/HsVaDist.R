#' Homo sapiens V-alpha distance matrix
#'
#' Precomputed Human V-alpha distance matrix based on IMGT multiple AA sequence alignment of CDR1, CDR2 and CDR2.5
#'
#' @docType data
#'
#' @usage data(HsVaDist)
#'
#' @format An object of class \code{"dist"}.
#'
#' @keywords datasets
#'
#'
#'
#' @examples
#' data(HsVaDist)
#' \donttest{
#' pheatmap(as.matrix(HsVaDist), color=viridis::viridis(100), border_color = NA, cellheight = 2.5, cellwidth = 2.5, main = "V-alpha distance based on IMGT CDR1, CDR2 & CDR2.5 AA sequences")
#' }
"HsVaDist"
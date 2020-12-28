#' Homo sapiens V-beta distance matrix
#'
#' Precomputed Human V-beta distance matrix based on IMGT multiple AA sequence alignment of CDR1, CDR2 and CDR2.5
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
#' data(HsVbDist)
#' \donttest{
#' pheatmap(as.matrix(HsVbDist), color=viridis::viridis(100), border_color = NA, cellheight = 2.5, cellwidth = 2.5, main = "V-alpha distance based on IMGT CDR1, CDR2 & CDR2.5 AA sequences")
#' }
"HsVbDist"

<!-- README.md is generated from README.Rmd. Please edit that file -->

# TCRdist

TCRdist provides methods to cluster T-cell receptors and identify
similar motifs within their CDR regions.

## Installation

Currently TCRdist requires the Seqan headers provided by the RSeqan
package, the pacakge currently links to the Boost headers provided by
the BH package, thus it must also be installed - these are primarily
used in some utility diagnostic functions (in the dev branch). Please
refer to each of these packages for their installation requirements.

``` r
install.packages(c("Rcpp", "BH"))
BiocManager::install("RSeqan")
install_github("JulianSpagnuolo/TCRdist")
```

## Citation

It is requested that any published or presented work that utilised this
package and scripts contained within cite TCRdist.

    #> 
    #> To cite package 'TCRdist' in publications use:
    #> 
    #>   Julian Spagnuolo (2020). TCRdist: T-cell Receptor Distance and
    #>   Similarity Analysis. R package version 0.0.1.
    #> 
    #> A BibTeX entry for LaTeX users is
    #> 
    #>   @Manual{,
    #>     title = {TCRdist: T-cell Receptor Distance and Similarity Analysis},
    #>     author = {Julian Spagnuolo},
    #>     year = {2020},
    #>     note = {R package version 0.0.1},
    #>   }
    #> 
    #> ATTENTION: This citation information has been auto-generated from the
    #> package DESCRIPTION file and may need manual editing, see
    #> 'help("citation")'.

The original paper from which TCRdist was ported to R should also be
cited:

Quantifiable predictive features define epitope-specific T cell receptor
repertoires

Pradyot Dash, Andrew J. Fiore-Gartland, Tomer Hertz, George C. Wang,
Shalini Sharma, Aisha Souquette, Jeremy Chase Crawford, E. Bridie
Clemens, Thi H. O. Nguyen, Katherine Kedzierska, Nicole L. La Gruta,
Philip Bradley & Paul G. Thomas

Nature (2017) <doi:10.1038/nature22383>

## Example

## NOTE:

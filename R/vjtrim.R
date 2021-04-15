

VJtrim <- function(cdr, vgene, jgene)
{
  ##' @title VJtrim
  ##' @name VJtrim
  ##' @author Julian Spagnuolo
  ##' @description trims V and J sequences from CDR3 amino acid sequences based on the IMGT reference.
  ##'
  ##' @param 
  ##' @export
  require(TCRdist)
  
  data("IMGT_Vab_Hsap")
  
  # convert string to vector of chars
  cdr <- strsplit(cdr, "*")
  
  if(isTRUE(str_detect(vgene, "\\*")))
  {
    vgene <- str_split(ab.hsap[which(ab.hsap$id == vgene),"cdrs"], ";", simplify = T)[,4]
    vgene <- str_remove_all(vgene, "\\.")
  }else{
    vgene <- str_split(ab.hsap[grep(vgene, ab.hsap$id),"cdrs"],";", simplify = T)[,4]
    vgene <- str_remove_all(vgene, "\\.")
    vgene <- unique(vgene)
  }
  
  
  if(isTRUE(str_detect(jgene, "\\*")))
  {
    jgene <- str_remove_all(ab.hsap[which(ab.hsap$id == jgene),"cdrs"], "\\.")
  }else{
    jgene <- str_remove_all(ab.hsap[grep(jgene, ab.hsap$id),"cdrs"], "\\.")
    jgene <- unique(jgene)
  }
  
  
  if(length(vgene) == 1)
  {
    vgene <- strsplit(vgene, "*")
    matches <- vector(mode="integer")
    for(i in 1:length(vgene))
    {
      if(vgene[i] == cdr[i])
      {
        matches <- append(matches, i)
      }
      vrange <- c(min(matches), max(matches))
    }
  }else{
    # find best matching vgene
    
  }
  
  if(length(jgene) == 1)
  {
    jgene <- str_split(jgene, "*")
    
    
    
  }
  
}
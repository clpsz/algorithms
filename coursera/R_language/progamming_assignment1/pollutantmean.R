pollutantmean <- function(directory = "specdata", pollutant = "sulfate", id = 1:332) {
	#source("pt1.R")
	#pollutantmean("specdata", "sulfate", 1:10)
	## 'directory' is a character vector of length 1 indicating
	## the location of the CSV files

	## 'pollutant' is a character vector of length 1 indicating
	## the name of the pollutant for which we will calculate the
	## mean; either "sulfate" or "nitrate".

	## 'id' is an integer vector indicating the monitor ID numbers
	## to be used

	## Return the mean of the pollutant across all monitors list
	## in the 'id' vector (ignoring NA values)
	## NOTE: Do not round the result!

	sum = 0
	goodlines = 0
	badlines = 0
	
	
	if (pollutant == "sulfate") {
		care_col = 2
	}
	else {
		care_col = 3
	}
	for (i in 1:length(id)) {
		filename = paste(directory, "/", sprintf("%03d.csv", id[[i]]), sep="")
		tbl = read.table(filename, sep=",", header=TRUE)
		rows = dim(tbl)[[1]]
		for (i in 1:rows) {
			this_row = tbl[i, ]
			if (!is.na(this_row[[care_col]])) {
				#print(this_row[[care_col]])
				sum = sum + this_row[[care_col]]
				goodlines = goodlines + 1
			} else {
				badlines = badlines + 1
			}
		}
	}
	
	sum / goodlines
}


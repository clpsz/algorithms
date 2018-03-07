complete <- function(directory = 'specdata', id = 1:332) {
	## 'directory' is a character vector of length 1 indicating
	## the location of the CSV files

	## 'id' is an integer vector indicating the monitor ID numbers
	## to be used
	
	## Return a data frame of the form:
	## id nobs
	## 1  117
	## 2  1041
	## ...
	## where 'id' is the monitor ID number and 'nobs' is the
	## number of complete cases
	
	care_len = length(id)
	nobs = vector(mode = "numeric", length = length(id))
	cur_row = 1

	
	for (i in 1:length(id)) {
		filename = paste(directory, "/", sprintf("%03d.csv", id[[i]]), sep="")
		tbl = read.table(filename, sep=",", header=TRUE)
		rows = dim(tbl)[[1]]
		count = 0
		for (i in 1:rows) {
			this_row = tbl[i, ]
			if (!is.na(this_row[[1]]) &&
				!is.na(this_row[[2]]) &&
				!is.na(this_row[[3]]) &&
				!is.na(this_row[[4]])) {
				count = count + 1
				#print(this_row[[care_col]])
			}
		}
		
		nobs[[cur_row]] = count
		cur_row = cur_row + 1
	}
	
	data.frame(id, nobs)
}
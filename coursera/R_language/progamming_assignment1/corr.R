corr <- function(directory = 'specdata', threshold = 0) {
	## 'directory' is a character vector of length 1 indicating
	## the location of the CSV files

	## 'threshold' is a numeric vector of length 1 indicating the
	## number of completely observed observations (on all
	## variables) required to compute the correlation between
	## nitrate and sulfate; the default is 0

	## Return a numeric vector of correlations
	## NOTE: Do not round the result!
	
	res = vector(mode = "numeric", length = 332)
	all_count = 0
	
	for (i in 1:332) {
		filename = paste(directory, "/", sprintf("%03d.csv", i), sep="")
		tbl = read.table(filename, sep=",", header=TRUE)
		rows = dim(tbl)[[1]]
		count = 0
		sulf = vector(mode = "numeric", length = rows)
		nitr = vector(mode = "numeric", length = rows)
		for (i in 1:rows) {
			this_row = tbl[i, ]
			if (!is.na(this_row[[1]]) &&
				!is.na(this_row[[2]]) &&
				!is.na(this_row[[3]]) &&
				!is.na(this_row[[4]])) {
				count = count + 1
				sulf[[count]] = this_row[[2]]
				nitr[[count]] = this_row[[3]]
			}
		}
		
		if (count > threshold) {
			#print(cor(sulf, nitr))
			length(sulf) = count
			length(nitr) = count
			
			all_count = all_count + 1
			res[[all_count]] = cor(sulf, nitr)
			#print(cor(sulf, nitr))
			#break
		}
	}

	length(res) = all_count
	res
}
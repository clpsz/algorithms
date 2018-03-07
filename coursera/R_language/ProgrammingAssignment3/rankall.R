rankhospital <- function(state, outcome, num = "best", data) {
	## Check that state and outcome are valid
#	valid_states <- data[,7][!is.na(data[,7])]
#	valid_states = unique(valid_states)
#	if (! state %in% valid_states)
#		stop("invalid state")
#		
#	valid_outcomes <- c("heart attack", "heart failure", "pneumonia")
#	if (! outcome %in% valid_outcomes)
#		stop("invalid outcome")

	## Return hospital name in that state with the given rank
	## 30-day death rate
	if (outcome == "heart attack")
		col_num = 11
	if (outcome == "heart failure")
		col_num = 17
	if (outcome == "pneumonia")
		col_num = 23
		
			
	data_needed <- cbind(data[,2], data[,7], as.numeric(data[,col_num]))
		
	# filter na
	index <- !is.na(data_needed[,3])
	data_needed <- cbind(data_needed[,1][index], data_needed[,2][index], data_needed[,3][index])
	# filter state
	index <- data_needed[,2] == state
	data_needed <- cbind(data_needed[,1][index], data_needed[,2][index], data_needed[,3][index])
	
	# order
	data_needed = data_needed[order(as.numeric(data_needed[,3]), data_needed[,1]),]
	
	
	if (class(data_needed) == "character") {
		if (num == "best" || num == 1)
			data <- data_needed[1]
		else
			data <- NA
	}
	else if (num == "best")
		data <- data_needed[,1][1]
	else if (num == "worst")
		data <- data_needed[,1][length(data_needed[,1])]
	else
		data <- data_needed[,1][num]

	#data_needed
	data
}

rankall <- function(outcome, num = "best") {
	## Read outcome data
	data <- read.csv("outcome-of-care-measures.csv", colClasses = "character")
	
	## get all valid states
	valid_states <- data[,7][!is.na(data[,7])]
	valid_states = unique(valid_states)
	
	## Check that state and outcome are valid
	valid_outcomes <- c("heart attack", "heart failure", "pneumonia")
	if (! outcome %in% valid_outcomes)
		stop("invalid outcome")


	hospitals <- vector()
	for (st in valid_states) {
		hospitals <- c(hospitals, rankhospital(st, outcome, num, data))
	}
	
	output <- cbind(hospitals, states)
	colnames(output) <- c("hospital", "state")
	output <- output[order(output[,2]),]
	as.data.frame(output)
#		
	## For each state, find the hospital of the given rank
	## Return a data frame with the hospital names and the
	## (abbreviated) state name
}

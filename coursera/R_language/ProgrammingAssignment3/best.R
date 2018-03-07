best <- function(state, outcome) {
	## Read outcome data
	data <- read.csv("outcome-of-care-measures.csv", colClasses = "character")

	## Check that state and outcome are valid
	valid_states <- data[,7][!is.na(data[,7])]
	valid_states = unique(valid_states)
	if (! state %in% valid_states)
		stop("invalid state")
		
	valid_outcomes <- c("heart attack", "heart failure", "pneumonia")
	if (! outcome %in% valid_outcomes)
		stop("invalid outcome")
		
	
		
	## Return hospital name in that state with lowest 30-day death
	## rate
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
	
	
	min_count <- min(as.numeric(data_needed[,3]))
	min_index <- data_needed[,3] == min_count
	min_name <- data_needed[,1][min_index]
	
	
	#print(min_count)
	
	#data_needed
	
	
	#min_name[1]
	#print(data_needed)
	#print(min_count)
	#print(min_name)
	#print(sort(min_name)[1])
	
	#print(min_count)
	#print(min_name)
	sort(min_name)[1]
}

## Put comments here that give an overall description of what your
## functions do

## create a closure with data x
makeCacheMatrix <- function(x = matrix()) {
	i <- NULL
	set <- function(y) {
		x <<- y
		i <<- NULL
	}
	get <- function() x
	
	setInverse <- function(inv) i <<- inv
	getInverse <- function() i
	
	list (set = set, get = get,
	setInverse = setInverse,
	getInverse = getInverse)
}


## x should be returned by makeCacheMatrix
cacheSolve <- function(x, ...) {
    ## Return a matrix that is the inverse of 'x'
	i <- x$getInverse()
	if (!is.null(i)) {
		message("getting cache data")
		return(i)
	}
	data <- x$get()
	i <- solve(data)
	x$setInverse(i)
	i
}

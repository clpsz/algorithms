package _118_pascals_triangle

func generate(numRows int) [][]int {
	res := make([][]int, numRows, numRows)

	for i := 0; i < numRows; i++ {
		level := i+1
		levelRes := make([]int, level, level)
		for j := 0; j < level; j++ {
			if j == 0 || j == level-1 {
				levelRes[j] = 1
			} else {
				levelRes[j] = res[i-1][j-1] + res[i-1][j]
			}
		}
		res[i] = levelRes
	}

	return res
}

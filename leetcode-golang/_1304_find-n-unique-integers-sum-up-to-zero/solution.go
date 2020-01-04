package _1304_find_n_unique_integers_sum_up_to_zero

func sumZero(n int) []int {
	if n == 0 {
		return nil
	}
	res := make([]int, 0)
	i, j := n/2, n%2
	if j != 0 {
		res = append(res, 0)
	}

	for ii := 1; ii <= i; ii++ {
		res = append(res, ii, -1*ii)
	}

	return res
}

package _22_generate_parentheses

func generateParenthesis(n int) []string {
	var inner func (left, right int) []string
	inner = func(left, right int) []string {
		var res []string

		if left == 0 && right == 0 {
			return []string{""}
		}
		if left < right {
			for _, e := range inner(left, right-1) {
				res = append(res, ")"+e)
			}
		}
		if left > 0 {
			for _, e := range inner(left-1, right) {
				res = append(res, "("+e)
			}
		}
		return res
	}
	return inner(n, n)
}

package _20_valid_parentheses

func isValid(s string) bool {
	stack := make([]rune, 0)
	var target rune

	for _, r := range s {
		if r == '(' || r == '[' || r == '{' {
			stack = append(stack, r)
			continue
		}
		switch r {
		case ')':
			target = '('
		case ']':
			target = '['
		case '}':
			target = '{'
		}
		if len(stack) < 1 || stack[len(stack)-1] != target {
			return false
		}
		stack = stack[:len(stack)-1]
	}
	return len(stack) == 0
}

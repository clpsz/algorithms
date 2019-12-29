package _20_valid_parentheses

import "testing"

func TestIsValid(t *testing.T) {
	cases := []struct{
		input string
		want bool
	} {
		{"()", true},
		{"(]", false},
	}

	for _, c := range cases {
		res := isValid(c.input)
		if res != c.want {
			t.Errorf("input %s, got %t, want %t", c.input, res, c.want)
		}
	}
}

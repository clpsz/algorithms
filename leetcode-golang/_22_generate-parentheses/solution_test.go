package _22_generate_parentheses

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestGenerateParentheses(t *testing.T) {
	cases := []struct{
		input int
		want []string
	} {
		{1, []string{"()"}},
		{2, []string{"(())", "()()"}},
		{3, []string{"()()()", "()(())", "(())()", "((()))", "(()())"}},
	}

	for _, c := range cases {
		res := generateParenthesis(c.input)
		assert.ElementsMatch(t, res, c.want)
	}
}

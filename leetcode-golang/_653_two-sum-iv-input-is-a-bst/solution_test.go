package _653_two_sum_iv_input_is_a_bst

import (
	. "leetcode-golang/commons"
	"testing"
)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func TestFindTarget(t *testing.T) {
	cases := []struct{
		input string
		target int
		want bool
	} {
		{"[5,3,6,2,4,7]", 9, true},
		{"[5,3,6,2,4,7]", 28, false},
		{"[5]", 10, false},
		{"[5,4]", 10, false},
		{"[5,4,6]", 10, true},
	}

	for _, c := range cases {
		res := findTarget(DeserializeLC(c.input), c.target)
		if res != c.want {
			t.Errorf("input %s, got %t, want %t", c.input, res, c.want)
		}
	}

}

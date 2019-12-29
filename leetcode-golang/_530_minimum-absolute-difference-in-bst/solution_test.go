package _530_minimum_absolute_difference_in_bst

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
func TestGetMinimumDifference(t *testing.T) {
	cases := []struct{
		input string
		want int
	} {
		{"[236,104,701,null,227,null,911]", 9},
		{"[1,null,3,2]", 1},
	}

	for _, c := range cases {
		r := getMinimumDifference(DeserializeLC(c.input))
		if r != c.want {
			t.Errorf("input %s, got %d, want %d", c.input, r, c.want)
		}
	}
}

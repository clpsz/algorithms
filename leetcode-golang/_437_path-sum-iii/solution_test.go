package _437_path_sum_iii

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
func TestPathSum(t *testing.T) {
	cases := []struct{
		input string
		sum int
		want int
	} {
		{"[10,5,-3,3,2,null,11,3,-2,null,1]", 8, 3},
		{"[1,-2,-3,1,3,-2,null,-1]", -1, 4},

	}

	for _, c := range cases {
		r := pathSum(DeserializeLC(c.input), c.sum)
		if r != c.want {
			t.Errorf("input %s, got %d, want %d", c.input, r, c.want)
		}
	}
}

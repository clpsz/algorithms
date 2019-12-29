package _669_trim_a_binary_search_tree

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
func TestTrimBST(t *testing.T) {
	cases := []struct{
		input string
		L, R int
		want string
	} {
		{"[1,0,2]", 1, 2, "[1,null,2]"},
		{"[3,0,4,null,2,null,null,1]", 1, 3, "[3,2,null,1]"},
	}

	for _, c := range cases {
		res := SerializeLC(trimBST(DeserializeLC(c.input), c.L, c.R))
		if  res != c.want {
			t.Errorf("input %s, res %s, want %s", c.input, res, c.want)
		}
	}
}

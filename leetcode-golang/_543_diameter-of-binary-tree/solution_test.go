package _543_diameter_of_binary_tree

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
func TestDiameterOfBinaryTree(t *testing.T) {
	cases := []struct{
		input string
		want int
	} {
		{"[1,2,3,4,5]", 3},
	}

	for _, c := range cases {
		r := diameterOfBinaryTree(DeserializeLC(c.input))
		if r != c.want {
			t.Errorf("input %s, got %d, want %d", c.input, r, c.want)
		}
	}
}

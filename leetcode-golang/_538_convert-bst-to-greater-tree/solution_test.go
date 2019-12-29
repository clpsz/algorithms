package _538_convert_bst_to_greater_tree

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
func TestConvertBST(t *testing.T) {
	cases := []struct{
		input string
		want string
	} {
		{"[5,2,13]", "[18,20,13]"},
	}

	for _, c := range cases {
		r := SerializeLC(convertBST(DeserializeLC(c.input)))
		if r != c.want {
			t.Errorf("input %s, got %s, want %s", c.input, r, c.want)
		}
	}
}

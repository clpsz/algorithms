package _110_balanced_binary_tree

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
func TestIsBalanced(t *testing.T) {
	data := "[3,9,null,null,20,15,null,null,7,null,null]"
	res := isBalanced(Deserialize(data))
	want := true

	if res != want {
		t.Errorf("res %t, want %t", res, want)
	}

	data = "[1,2,3,4,null,null,4,null,null,3,null,null,2,null,null]"
	res = isBalanced(Deserialize(data))
	want = false
	if res != want {
		t.Errorf("res %t, want %t", res, want)
	}
}

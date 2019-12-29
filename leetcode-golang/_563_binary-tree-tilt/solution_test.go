package _563_binary_tree_tilt

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
func TestFindTilt(t *testing.T) {
	res := findTilt(DeserializeLC("[1,2,3]"))
	if res != 1 {
		t.Errorf("res %d, want %d", res, 1)
	}
}

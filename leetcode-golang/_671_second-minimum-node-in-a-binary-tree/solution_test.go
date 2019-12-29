package _671_second_minimum_node_in_a_binary_tree

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
func TestFindSecondMinimumValue(t *testing.T) {
	res := findSecondMinimumValue(DeserializeLC("[2,2,5,null,null,5,7]"))
	if res != 5 {
		t.Errorf("res %d, want %d", res, 5)
	}
	res = findSecondMinimumValue(DeserializeLC("[2,2,2]"))
	if res != -1 {
		t.Errorf("res %d, want %d", res, -1)
	}
	res = findSecondMinimumValue(DeserializeLC("[1,1,3,1,1,3,4,3,1,1,8]"))
	if res != 3 {
		t.Errorf("res %d, want %d", res, 3)
	}
}

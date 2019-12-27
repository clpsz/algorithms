package _1022_sum_of_root_to_leaf_binary_numbers

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
func TestSumRootToLeaf(t *testing.T) {
	var res int

	res = sumRootToLeaf(DeserializeLC("[1,0,1]"))
	if res != 5 {
		t.Errorf("res %d, want %d", res, 5)
	}
	res = sumRootToLeaf(DeserializeLC("[1,0,1,0,1,0,1]"))
	if res != 22 {
		t.Errorf("res %d, want %d", res, 22)
	}
	res = sumRootToLeaf(DeserializeLC("[1]"))
	if res != 1 {
		t.Errorf("res %d, want %d", res, 1)
	}
	res = sumRootToLeaf(DeserializeLC("[1,1,1]"))
	if res != 6 {
		t.Errorf("res %d, want %d", res, 6)
	}
}

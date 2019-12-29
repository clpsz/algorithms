package _897_increasing_order_search_tree

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
func TestIncreasingBST(t *testing.T) {
	res := SerializeLC(increasingBST(DeserializeLC("[5,3,6,2,4,null,8,1,null,null,null,7,9]")))
	want := "[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]"

	if res != want {
		t.Errorf("res %s, want %s", res, want)
	}
}

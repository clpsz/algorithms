package _872_leaf_similar_trees

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
func TestLeafSimilar(t *testing.T) {
	res := leafSimilar(DeserializeLC("[3,5,1,6,2,9,8,null,null,7,4]"), DeserializeLC("[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]"))
	if res != true {
		t.Errorf("res %t, want %t", res, true)
	}
}

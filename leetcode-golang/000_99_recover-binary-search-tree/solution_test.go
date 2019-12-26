package _00_99_recover_binary_search_tree

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
func TestRecoverTree(t *testing.T) {
	data := "[3,1,null,null,4,2,null,null,null]"
	tree := Deserialize(data)
	recoverTree(tree)
	res := Serialize(tree)
	t.Logf("%v", res)
}

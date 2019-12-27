package _257_binary_tree_paths

import (
	"leetcode-golang/commons"
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
func TestBinaryTreePaths(t *testing.T)  {
	data := "[1,2,3,null,5]"
	tree := commons.DeserializeLC(data)
	paths := binaryTreePaths(tree)
	for _, p := range paths {
		t.Log(p)
	}
}

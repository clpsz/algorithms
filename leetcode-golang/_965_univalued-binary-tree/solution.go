package _965_univalued_binary_tree

import (
	. "leetcode-golang/commons"
)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isUnivalTree(root *TreeNode) bool {
	var helper func(root *TreeNode, val int) bool
	helper = func(root *TreeNode, val int) bool {
		if root == nil {
			return true
		}

		return root.Val == val && helper(root.Left, val) && helper(root.Right, val)
	}
	if root == nil {
		return true
	}

	return helper(root, root.Val)
}

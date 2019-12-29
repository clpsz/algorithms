package _897_increasing_order_search_tree

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
func increasingBST(root *TreeNode) *TreeNode {
	newRoot := &TreeNode{Val: -1}
	curRoot := newRoot

	var helper func(root *TreeNode)
	helper = func(root *TreeNode) {
		if root == nil {
			return
		}

		helper(root.Left)
		curRoot.Right = &TreeNode{Val: root.Val}
		curRoot = curRoot.Right
		helper(root.Right)
	}
	helper(root)

	return newRoot.Right
}

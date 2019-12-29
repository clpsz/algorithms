package _993_cousins_in_binary_tree

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
func isCousins(root *TreeNode, x int, y int) bool {
	var parentX, parentY *TreeNode
	var depthX, depthY int

	var findParent func(root *TreeNode, depth int)
	findParent = func(root *TreeNode, depth int) {
		if root == nil {
			return
		}

		if (root.Left != nil && root.Left.Val == x) ||
			(root.Right != nil && root.Right.Val == x) {
			parentX = root
			depthX = depth
		}
		if (root.Left != nil && root.Left.Val == y) ||
			(root.Right != nil && root.Right.Val == y) {
			parentY = root
			depthY = depth
		}

		findParent(root.Left, depth+1)
		findParent(root.Right, depth+1)
	}

	findParent(root, 0)
	if parentX != nil && parentY != nil && parentX != parentY && depthX == depthY {
		return true
	}

	return false
}

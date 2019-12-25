package _404_sum_of_left_leaves

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
func sumOfLeftLeaves(root *TreeNode) int {
	var helper func (root *TreeNode, isLeft bool) int
	helper = func (root *TreeNode, isLeft bool) int {
		if root == nil {
			return 0
		}
		if isLeft && root.Left == nil && root.Right == nil {
			return root.Val
		}

		return helper(root.Left, true) + helper(root.Right, false)
	}

	return helper(root, false)
}

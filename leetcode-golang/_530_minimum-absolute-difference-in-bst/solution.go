package _530_minimum_absolute_difference_in_bst

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
func getMinimumDifference(root *TreeNode) int {
	last := -1
	minAbsDiff := -1
	var helper func(root *TreeNode)
	helper = func(root *TreeNode) {
		if root == nil {
			return
		}
		helper(root.Left)

		if last != -1 && (minAbsDiff == -1 || minAbsDiff > root.Val-last) {
			minAbsDiff = root.Val - last
		}
		last = root.Val

		helper(root.Right)
	}

	helper(root)

	return minAbsDiff
}

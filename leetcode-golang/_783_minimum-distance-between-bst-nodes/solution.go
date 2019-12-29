package _783_minimum_distance_between_bst_nodes

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
func minDiffInBST(root *TreeNode) int {
	lastVal := -1
	minDiff := -1

	var helper func(root *TreeNode)
	helper = func(root *TreeNode) {
		if root == nil {
			return
		}

		helper(root.Left)
		if lastVal > 0 {
			diff := root.Val - lastVal
			if minDiff < 0 {
				minDiff = diff
			} else {
				if diff < minDiff {
					minDiff = diff
				}
			}
		}
		lastVal = root.Val
		helper(root.Right)
	}

	helper(root)
	return minDiff
}

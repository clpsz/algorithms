package _563_binary_tree_tilt

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
func findTilt(root *TreeNode) int {
	var sumTilt int

	var tiltAndSum func(root *TreeNode) (int, int)
	tiltAndSum = func(root *TreeNode) (int, int) {
		if root == nil {
			return 0, 0
		}

		_, leftSum := tiltAndSum(root.Left)
		_, rightSum := tiltAndSum(root.Right)
		var tilt int
		if leftSum > rightSum {
			tilt = leftSum-rightSum
		} else {
			tilt = rightSum-leftSum
		}
		sumTilt += tilt
		return tilt, leftSum+rightSum+root.Val
	}

	if root == nil {
		return 0
	}

	tiltAndSum(root)
	return sumTilt
}

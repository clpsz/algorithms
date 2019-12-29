package _671_second_minimum_node_in_a_binary_tree

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
func findSecondMinimumValue(root *TreeNode) int {
	var helper func(root *TreeNode, parentVal int) int
	helper = func(root *TreeNode, parentVal int) int {
		if root == nil {
			return -1
		}
		if root.Val != parentVal {
			return root.Val
		}

		left := helper(root.Left, root.Val)
		right := helper(root.Right, root.Val)

		min := -1
		if left > 0 && right > 0 {
			min = left
			if right < left {
				min = right
			}
		} else {
			if left > 0 {
				min = left
			}
			if right > 0 {
				min = right
			}
		}

		if min > 0 {
			return min
		}

		return -1
	}

	return helper(root, root.Val)
}

package _1022_sum_of_root_to_leaf_binary_numbers

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
func sumRootToLeaf(root *TreeNode) int {
	var helper func(root1 *TreeNode, sum *int, parentVal int)
	helper = func(root1 *TreeNode, sum *int, parentVal int) {
		parentVal <<= 1
		parentVal += root1.Val

		if root1.Left == nil && root1.Right == nil {
			*sum += parentVal
			return
		}
		if root1.Left != nil {
			helper(root1.Left, sum, parentVal)
		}
		if root1.Right != nil {
			helper(root1.Right, sum, parentVal)
		}
	}

	if root == nil {
		return 0
	}

	sum := 0
	helper(root, &sum, 0)
	return sum
}

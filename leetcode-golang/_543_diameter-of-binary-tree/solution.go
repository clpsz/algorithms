package _543_diameter_of_binary_tree

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
func diameterOfBinaryTree(root *TreeNode) int {
	max := 0
	var helper func(root *TreeNode) int
	helper = func(root *TreeNode) int {
		if root == nil {
			return 0
		}
		hl := helper(root.Left)
		hr := helper(root.Right)
		if hl+hr > max {
			max = hl+hr
		}
		if hl > hr {
			return hl+1
		} else {
			return hr+1
		}
	}

	helper(root)
	return max
}

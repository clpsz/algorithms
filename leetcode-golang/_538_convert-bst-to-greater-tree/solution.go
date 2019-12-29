package _538_convert_bst_to_greater_tree

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
func convertBST(root *TreeNode) *TreeNode {
	sumOfGreater := 0

	var helper func(root *TreeNode)
	helper = func(root *TreeNode) {
		if root == nil {
			return
		}

		helper(root.Right)
		root.Val, sumOfGreater = root.Val+sumOfGreater, sumOfGreater+root.Val
		helper(root.Left)
	}

	helper(root)

	return root
}

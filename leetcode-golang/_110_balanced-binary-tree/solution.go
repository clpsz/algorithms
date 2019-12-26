package _110_balanced_binary_tree

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
func isBalanced(root *TreeNode) bool {
	var helper func (root1 *TreeNode) (height int, balanced bool)
	helper = func (root1 *TreeNode) (height int, balanced bool) {
		if root1 == nil {
			return 0, true
		}

		leftHeight, leftBalanced := helper(root1.Left)
		rightHeight, rightBalanced := helper(root1.Right)

		max, diff := func (a, b int) (int, int) { // get max height and height difference
			if a > b {
				return a, a-b
			}

			return b, b-a

		} (leftHeight, rightHeight)

		balanced = false
		if diff <= 1 && leftBalanced && rightBalanced{
			balanced = true
		}

		return max+1, balanced
	}

	_, balanced := helper(root)
	return balanced
}

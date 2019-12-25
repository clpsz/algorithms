package _687_longest_univalue_path

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
func longestUnivaluePath(root *TreeNode) int {
	curMax := 0
	var helper func (root1 *TreeNode) int
	helper = func (root1 *TreeNode) int {
		if root1 == nil {
			return 0
		}
		lengthLeft := helper(root1.Left)
		lengthRight := helper(root1.Right)
		lengthLeftWithRoot := 0
		lengthRightWithRoot := 0

		if root1.Left != nil && root1.Left.Val == root1.Val {
			lengthLeftWithRoot = lengthLeft + 1
		}
		if root1.Right != nil && root1.Right.Val == root1.Val {
			lengthRightWithRoot = lengthRight + 1
		}
		thisMax := lengthLeftWithRoot + lengthRightWithRoot
		if thisMax > curMax {
			curMax = thisMax
		}
		if lengthLeftWithRoot > lengthRightWithRoot {
			return lengthLeftWithRoot
		} else {
			return lengthRightWithRoot
		}
	}

	helper(root)
	return curMax
}

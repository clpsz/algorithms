package _938_range_sum_of_bst

import (
	. "leetcode-golang/commons"
)


func rangeSumBST(root *TreeNode, L int, R int) int {
	var helper func (root1 *TreeNode) int
	helper = func(root1 *TreeNode) int {
		if root1 == nil { return 0}
		sum := 0
		if root1.Val >= L && root1.Val <= R {
			sum += root1.Val
		}
		if root1.Val > L {
			sum += helper(root1.Left)
		}
		if root1.Val < R {
			sum += helper(root1.Right)
		}
		return sum
	}

	return helper(root)
}
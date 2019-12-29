package _437_path_sum_iii

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
func pathSum(root *TreeNode, sum int) int {
	var pathSumStartFrom func(root *TreeNode, sum int) int
	pathSumStartFrom = func(root *TreeNode, sum int) int {
		res := 0
		if root == nil {
			return 0
		}

		if root.Val == sum {
			res += 1
		}

		return res + pathSumStartFrom(root.Left, sum-root.Val) + pathSumStartFrom(root.Right, sum-root.Val)
	}

	res := 0

	var helper func(root *TreeNode)
	helper = func(root *TreeNode) {
		if root == nil {
			return
		}
		res += pathSumStartFrom(root, sum)
		helper(root.Left)
		helper(root.Right)
	}

	helper(root)

	return res
}

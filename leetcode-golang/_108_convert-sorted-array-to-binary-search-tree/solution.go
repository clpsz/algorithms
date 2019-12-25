package _108_convert_sorted_array_to_binary_search_tree

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
func sortedArrayToBST(nums []int) *TreeNode {
	if len(nums) == 0 {
		return nil
	}
	mid := len(nums) / 2
	res := TreeNode{Val: nums[mid]}
	res.Left = sortedArrayToBST(nums[:mid])
	res.Right = sortedArrayToBST(nums[mid+1:])

	return &res
}

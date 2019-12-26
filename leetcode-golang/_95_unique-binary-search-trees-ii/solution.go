package _95_unique_binary_search_trees_ii

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
func generateTrees(n int) []*TreeNode {
	var helper func (start, end int) []*TreeNode
	helper = func (start, end int) []*TreeNode {
		if start > end {
			return []*TreeNode{nil}
		}
		res := make([]*TreeNode, 0)

		for i := start; i <= end; i++ {
			leftTrees := helper(start, i-1)
			rightTrees := helper(i+1, end)

			for _, lt := range leftTrees {
				for _, rt := range rightTrees {
					root := TreeNode{Val: i}
					root.Left = lt
					root.Right = rt
					res = append(res, &root)
				}
			}
		}
		return res
	}
	if n == 0 {
		return nil
	}

	return helper(1, n)
}
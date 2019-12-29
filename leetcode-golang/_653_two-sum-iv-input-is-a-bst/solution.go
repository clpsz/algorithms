package _653_two_sum_iv_input_is_a_bst

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
func findTarget(root *TreeNode, k int) bool {
	m := make(map[int]*TreeNode)

	var helper func(root *TreeNode)
	helper = func(root *TreeNode) {
		if root == nil {
			return
		}

		m[root.Val] = root
		helper(root.Left)
		helper(root.Right)
	}

	helper(root)
	for kk, e := range m {
		target := k - kk

		if ee, ok := m[target]; ok && ee != e {
			return true
		}
	}

	return false
}

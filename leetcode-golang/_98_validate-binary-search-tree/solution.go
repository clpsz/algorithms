package _98_validate_binary_search_tree

import (
	. . "leetcode-golang/commons"
)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isValidBST(root *TreeNode) bool {
	nodes := make([]int, 0)
	var helper func (root1 *TreeNode)
	helper = func (root1 *TreeNode) {
		if root1 == nil {
			return
		}
		helper(root1.Left)
		nodes = append(nodes, root1.Val)
		helper(root1.Right)
	}

	helper(root)

	if len(nodes) == 0 {
		return true
	}

	last := nodes[0]
	nodes = nodes[1:]
	for _, node := range nodes {
		if last > node {
			return false
		}
		last = node
	}
	return true
}
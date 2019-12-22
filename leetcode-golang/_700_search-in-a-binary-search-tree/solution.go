package _700_search_in_a_binary_search_tree

import "leetcode-golang/commons"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func searchBST(root *commons.TreeNode, val int) *commons.TreeNode {
	if root == nil {
		return nil
	}

	if root.Val == val {
		return root
	}
	if val > root.Val {
		return searchBST(root.Right, val)
	} else {
		return searchBST(root.Left, val)
	}
}

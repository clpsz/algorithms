package _257_binary_tree_paths

import (
	. "leetcode-golang/commons"
	"strconv"
)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func binaryTreePaths(root *TreeNode) []string {
	if root == nil {
		return nil
	}

	valStr := strconv.Itoa(root.Val)
	valArrow := valStr + "->"
	if root.Left == nil && root.Right == nil {
		return []string{valStr}
	}

	var res []string
	if root.Left != nil {
		for _, path := range binaryTreePaths(root.Left) {
			res = append(res, valArrow + path)
		}
	}
	if root.Right != nil {
		for _, path := range binaryTreePaths(root.Right) {
			res = append(res, valArrow + path)
		}
	}

	return res
}

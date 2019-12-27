package _872_leaf_similar_trees

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
func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	var getLeafList func(root *TreeNode) []int
	getLeafList = func(root *TreeNode) []int {
		if root == nil {
			return nil
		}
		if root.Left == nil && root.Right == nil {
			return []int{root.Val}
		}

		var res []int
		res = append(res, getLeafList(root.Left)...)
		res = append(res, getLeafList(root.Right)...)
		return res
	}

	leftLeafList := getLeafList(root1)
	rightLeafList := getLeafList(root2)
	for i, e := range leftLeafList {
		if len(rightLeafList) <= i || rightLeafList[i] != e {
			return false
		}
	}

	return true
}

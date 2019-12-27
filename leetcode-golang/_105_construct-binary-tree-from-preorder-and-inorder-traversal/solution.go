package _105_construct_binary_tree_from_preorder_and_inorder_traversal

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
func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}

	inorderIndex := map[int]int{}
	for i, e := range inorder {
		inorderIndex[e] = i
	}

	root := &TreeNode{Val: preorder[0]}
	rootInOrderIndex := inorderIndex[preorder[0]]
	leftInOrder := inorder[:rootInOrderIndex]
	leftPreOrder := preorder[1:1+len(leftInOrder)]
	root.Left = buildTree(leftPreOrder, leftInOrder)

	rightInOrder := inorder[rootInOrderIndex+1:]
	rightPreOrder := preorder[1+len(leftInOrder):]
	root.Right = buildTree(rightPreOrder, rightInOrder)

	return root
}

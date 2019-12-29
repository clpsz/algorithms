package _606_construct_string_from_binary_tree

import (
	. "leetcode-golang/commons"
	"strconv"
	"strings"
)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func tree2str(root *TreeNode) string {
	nodeToStr := func(node *TreeNode) string {
		return strconv.Itoa(node.Val)
	}

	if root == nil {
		return ""
	}
	if root.Left == nil && root.Right == nil {
		return nodeToStr(root)
	}
	if root.Left == nil { // right != nil
		return strings.Join([]string{nodeToStr(root), "()", "(", tree2str(root.Right), ")"}, "")
	}
	if root.Right == nil { // left != nil
		return strings.Join([]string{nodeToStr(root), "(", tree2str(root.Left), ")"}, "")
	}
	return strings.Join([]string{nodeToStr(root), "(", tree2str(root.Left), ")", "(", tree2str(root.Right), ")"}, "")
}

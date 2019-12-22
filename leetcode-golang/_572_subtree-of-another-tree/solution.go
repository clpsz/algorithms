package _572_subtree_of_another_tree

import "leetcode-golang/commons"

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSubtree(s *commons.TreeNode, t *commons.TreeNode) bool {
	var isIdentical func (s *commons.TreeNode, t *commons.TreeNode) bool
	isIdentical = func (s *commons.TreeNode, t *commons.TreeNode) bool {
		if s == nil {
			return t == nil
		}
		if t == nil {
			return false
		}

		if s.Val != t.Val {
			return false
		}

		return isIdentical(s.Left, t.Left) && isIdentical(s.Right, t.Right)
	}

	if isIdentical(s, t) {
		return true
	}
	if s.Left != nil && isSubtree(s.Left, t) {
		return true
	}
	if s.Right != nil && isSubtree(s.Right, t) {
		return true
	}
	return false
}
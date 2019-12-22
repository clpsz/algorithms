package _617_merge_two_binary_trees

import "leetcode-golang/commons"

func mergeTrees(t1 *commons.TreeNode, t2 *commons.TreeNode) *commons.TreeNode {
	if t1 == nil {
		return t2
	}
	if t2 == nil {
		return t1
	}
	res := commons.TreeNode{Val: t1.Val+t2.Val}
	res.Left = mergeTrees(t1.Left, t2.Left)
	res.Right = mergeTrees(t1.Right, t2.Right)
	return &res
}
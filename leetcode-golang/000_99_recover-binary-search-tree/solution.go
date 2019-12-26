package _00_99_recover_binary_search_tree

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
func recoverTree(root *TreeNode)  {
	var before *TreeNode = nil
    var first, second *TreeNode

	cur := root
	for {
		if cur == nil {
			break
		}
		if cur.Left == nil {
			before = cur
			cur = cur.Right
		} else {
			pre := getPredecessor(cur)
			if pre.Right == nil {
				pre.Right = cur
				cur = cur.Left
			}
			if pre.Right == cur {
				before = cur

				pre.Right = nil
				cur = cur.Right
			}
		}
	}
}

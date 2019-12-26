package _00_99_recover_binary_search_tree

import (
	. "leetcode-golang/commons"
)

// https://en.wikipedia.org/wiki/Tree_traversal#Morris_in-order_traversal_using_threading
func inOrderTraverse(root *TreeNode) []int {
	res := make([]int, 0)

	cur := root
	for {
		if cur == nil {
			break
		}
		if cur.Left == nil {
			res = append(res, cur.Val)
			cur = cur.Right
		} else {
			pre := getPredecessor(cur)
			if pre.Right == nil {
				pre.Right = cur
				cur = cur.Left
			}
			if pre.Right == cur {
				res = append(res, cur.Val)
				pre.Right = nil
				cur = cur.Right
			}
		}
	}

	return res
}

func preOrderTraverse(root *TreeNode) []int {
	res := make([]int, 0)

	cur := root
	for {
		if cur == nil {
			break
		}
		if cur.Left == nil {
			res = append(res, cur.Val)
			cur = cur.Right
		} else {
			pre := getPredecessor(cur)
			if pre.Right == nil {
				res = append(res, cur.Val)
				pre.Right = cur
				cur = cur.Left
			}
			if pre.Right == cur {
				pre.Right = nil
				cur = cur.Right
			}
		}
	}

	return res
}

func getPredecessor(root *TreeNode) *TreeNode {
	pre := root
	if pre.Left != nil {
		pre = pre.Left
		for {
			if pre.Right == nil || pre.Right == root {
				break
			}
			pre = pre.Right
		}
	}
	return pre
}
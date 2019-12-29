package _501_find_mode_in_binary_search_tree

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
func findMode(root *TreeNode) []int {
	first := true
	var last, count, maxCount int
	var res []int

	var helper func(root *TreeNode)
	helper = func(root *TreeNode) {
		if root == nil {
			return
		}
		helper(root.Left)
		if first {
			first = false
			last = root.Val
			count = 1
		} else {
			if root.Val == last {
				count++
			} else {
				if count > maxCount {
					res = res[:0]
					res = append(res, last)
					maxCount = count
				} else if count == maxCount {
					res = append(res, last)
				}
				last, count = root.Val, 1
			}
		}
		helper(root.Right)
	}
	if root == nil {
		return nil
	}

	helper(root)

	if count > maxCount {
		res = res[:0]
		res = append(res, last)
	} else if count == maxCount {
		res = append(res, last)
	}

	return res
}

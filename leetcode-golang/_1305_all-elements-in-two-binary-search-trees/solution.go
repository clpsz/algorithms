package _1305_all_elements_in_two_binary_search_trees

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
func getAllElements(root1 *TreeNode, root2 *TreeNode) []int {
	res1, res2 := make([]int, 0), make([]int, 0)

	var helper func(root *TreeNode, target []int) []int
	helper = func(root *TreeNode, target []int) []int {
		if root == nil {
			return target
		}
		target = helper(root.Left, target)
		target = append(target, root.Val)
		target = helper(root.Right, target)
		return target
	}

	res1 = helper(root1, res1)
	res2 = helper(root2, res2)

	return func(s1, s2 []int) []int {
		result := make([]int, 0)
		for i1, i2 := 0, 0; i1 < len(s1) || i2 < len(s2); {
			var less int
			switch {
			case i1 == len(s1):
				less = 2
			case i2 == len(s2):
				less = 1
			case s1[i1] < s2[i2]:
				less = 1
			default:
				less = 2
			}

			if less == 1 {
				result = append(result, s1[i1])
				i1++
			} else {
				result = append(result, s2[i2])
				i2++
			}
		}

		return result
	} (res1, res2)
}

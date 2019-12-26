package _103_binary_tree_zigzag_level_order_traversal

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
func zigzagLevelOrder(root *TreeNode) [][]int {
	if root == nil {
		return nil
	}

	curLevel := []*TreeNode{root}
	res := make([][]int, 0)

	for {
		if len(curLevel) == 0 {
			break
		}
		levelRes := make([]int, 0)
		nextLevel := make([]*TreeNode, 0)
		for _, node := range curLevel {
			levelRes = append(levelRes, node.Val)
			if node.Left != nil {
				nextLevel = append(nextLevel, node.Left)
			}
			if node.Right != nil {
				nextLevel = append(nextLevel, node.Right)
			}
		}
		res = append(res, levelRes)
		curLevel = nextLevel
	}

	needReverse := false
	for i, level := range res {
		if needReverse {
			reversedRes := make([]int, len(level))

			for ii, val := range level {
				reversedRes[len(level)-ii-1] = val
			}
			res[i] = reversedRes
		}
		needReverse = !needReverse
	}

	return res
}

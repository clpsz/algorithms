package _637_average_of_levels_in_binary_tree

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
func averageOfLevels(root *TreeNode) []float64 {
	type levelStat struct {
		levelSum, levelCount int
	}

	var levelStats []levelStat
	var helper func(root *TreeNode, level int)
	helper = func(root *TreeNode, level int) {
		if root == nil {
			return
		}

		if len(levelStats) == level {
			levelStats = append(levelStats, levelStat{root.Val, 1})
		} else {
			levelStats[level].levelSum += root.Val
			levelStats[level].levelCount++
		}
		helper(root.Left, level+1)
		helper(root.Right, level+1)
	}

	helper(root, 0)

	var res []float64
	for _, e := range levelStats {
		res = append(res, float64(e.levelSum)/float64(e.levelCount))
	}

	return res
}

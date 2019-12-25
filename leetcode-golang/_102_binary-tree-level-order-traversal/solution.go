package _102_binary_tree_level_order_traversal

import (
	"leetcode-golang/commons"
)

func levelOrderUseQueue(root *commons.TreeNode) [][]int {
	if root == nil {
		return make([][]int, 0)
	}

	var result = make([][]int, 0)
	var curLevel = []*commons.TreeNode{root}

	for {
		if len(curLevel) == 0 {
			break
		}
		var levelResult = make([]int, 0)
		var nextLevel = make([]*commons.TreeNode, 0)
		for _, node := range curLevel {
			levelResult = append(levelResult, node.Val)
			if node.Left != nil {
				nextLevel = append(nextLevel, node.Left)
			}
			if node.Right != nil {
				nextLevel = append(nextLevel, node.Right)
			}
		}
		result = append(result, levelResult)
		curLevel = nextLevel
	}

	return result
}


func levelOrderUseRecursive(root *commons.TreeNode) [][]int {
	var helper func (root *commons.TreeNode, res [][]int, level int) [][]int
	helper = func (root *commons.TreeNode, res [][]int, level int) [][]int{
		if root == nil {
			return res
		}
		if len(res) == level {
			res = append(res, make([]int, 0))
		}
		res[level] = append(res[level], root.Val)
		res = helper(root.Left, res, level+1)
		res = helper(root.Right, res, level+1)
		return res
	}

	result := make([][]int, 0)

	result = helper(root, result, 0)
	return result
}

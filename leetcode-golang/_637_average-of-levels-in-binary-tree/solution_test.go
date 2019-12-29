package _637_average_of_levels_in_binary_tree

import (
	. "leetcode-golang/commons"
	"testing"
)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func TestAverageOfLevels(t *testing.T) {
	input := "[3,9,20,null,null,15,7]"
	res := averageOfLevels(DeserializeLC(input))
	for _, e := range res {
		println(e)
	}
}

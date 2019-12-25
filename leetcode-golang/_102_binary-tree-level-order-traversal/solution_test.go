package _102_binary_tree_level_order_traversal

import (
	"fmt"
	. "leetcode-golang/commons"
	"testing"
)


func TestLevelOrderUseQueue(t *testing.T) {
	root := TreeNode{Val: 2, Left: &TreeNode{Val: 3}, Right: &TreeNode{Val: 4}}
	res := levelOrderUseQueue(&root)
	for _, lst := range res {
		for _, val := range lst {
			fmt.Print(val)
			fmt.Print(" ")
		}

		fmt.Println()
	}
}

func TestLevelOrderUseRecursive(t *testing.T) {
	root := TreeNode{Val: 2, Left: &TreeNode{Val: 3}, Right: &TreeNode{Val: 4}}
	res := levelOrderUseRecursive(&root)
	for _, lst := range res {
		for _, val := range lst {
			fmt.Print(val)
			fmt.Print(" ")
		}

		fmt.Println()
	}
}

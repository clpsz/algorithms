package go_solution

import (
	"fmt"
	"strconv"
	"strings"
	"testing"
)

func deserialize(data string) *TreeNode {
	var helper func(data1 []string) (*TreeNode, []string)
	helper = func(data1 []string) (*TreeNode, []string) {
		nodeStr := data1[0]
		data1 = data1[1:]

		if nodeStr == "null" { // null means current path ends
			return nil, data1
		}
		val, _ := strconv.Atoi(nodeStr)
		node := TreeNode{Val: val}
		node.Left, data1 = helper(data1)
		node.Right, data1 = helper(data1)
		return &node, data1
	}

	if data == "[]" { // will never be [null]
		return nil
	}

	data = data[1 : len(data)-1]
	dataList := strings.Split(data, ",")
	res, _ := helper(dataList)
	return res
}

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

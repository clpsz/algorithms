package go_solution

import (
	"strconv"
	"strings"
	"testing"
)

func serialize(root *TreeNode) string {
	result := make([]string, 0)

	var helper func(root1 *TreeNode)
	helper = func(root1 *TreeNode) {
		if root1 == nil {
			result = append(result, "null")
			return
		}
		result = append(result, strconv.Itoa(root1.Val))
		helper(root1.Left)
		helper(root1.Right)
	}

	helper(root)
	if result[0] == "null" {
		return "[]"
	}

	return "[" + strings.Join(result, ",") + "]"
}

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

func TestMergeTrees(t *testing.T) {
	data1 := "[1,3,5,null,null,null,2,null,null]"
	tree1 := deserialize(data1)
	data2 := "[2,1,null,4,null,null,3,null,null]"
	tree2 := deserialize(data2)
	tree3 := mergeTrees(tree1, tree2)
	want := "[3,4,5,null,null,4,null,null,5,null,null]"

	data3 := serialize(tree3)
	if data3 != want {
		t.Errorf("get %s, want %s", data3, want)
	}
}

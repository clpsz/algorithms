package commons

import (
	"strconv"
	"strings"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func Serialize(root *TreeNode) string {
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

func Deserialize(data string) *TreeNode {
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

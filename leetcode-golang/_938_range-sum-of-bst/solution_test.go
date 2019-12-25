package _938_range_sum_of_bst

import (
	. "leetcode-golang/commons"
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

func TestRangeSumBST(t *testing.T) {
	data1 := "[10,5,3,null,null,7,null,null,15,null,18,null,null]"
	tree1 := deserialize(data1)
	sum1 := rangeSumBST(tree1, 7, 15)
	if sum1 != 32 {
		t.Errorf("range sum return %d, want %d", sum1, 32)
	}
}

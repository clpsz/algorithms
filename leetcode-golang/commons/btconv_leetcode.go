package commons

import (
	"strconv"
	"strings"
)

func SerializeLC(root *TreeNode) string {
	if root == nil {
		return "[]"
	}

	res := make([]string, 0)
	curLevel := []*TreeNode{root}
	for {
		if len(curLevel) == 0 {
			break
		}
		nextLevel := make([]*TreeNode, 0)
		hasNext := false

		for _, node := range curLevel {
			res = append(res, nodeToString(node))
			if node == nil {
				continue
			}
			nextLevel = append(nextLevel, node.Left, node.Right)
			if node.Left != nil || node.Right != nil {
				hasNext = true
			}
		}

		if !hasNext {
			break
		}

		curLevel = nextLevel
	}

	res = truncateNullString(res)
	return "[" + strings.Join(res, ",") + "]"
}

func nodeToString(node *TreeNode) string {
	if node == nil {
		return "null"
	}

	return strconv.Itoa(node.Val)
}

func truncateNullString(strList []string) []string {
	for i := len(strList)-1; i >= 0; i-- {
		if strList[i] != "null" {
			break
		}

		strList = strList[:i]
	}

	return strList
}

func DeserializeLC(data string) *TreeNode {
	if data == "[]" { // will never be [null]
		return nil
	}

	data = data[1 : len(data)-1]
	dataList := strings.Split(data, ",")

	root := stringToNode(dataList[0])
	curIndex := 0
	curLevel := []*TreeNode{root}

	for {
		nextLevel := make([]*TreeNode, 0)
		for _, node := range curLevel {
			curIndex++
			if curIndex >= len(dataList) {
				break
			}

			node.Left = stringToNode(dataList[curIndex])
			if node.Left != nil {
				nextLevel = append(nextLevel, node.Left)
			}
			curIndex++
			if curIndex >= len(dataList) {
				break
			}

			node.Right = stringToNode(dataList[curIndex])
			if node.Right != nil {
				nextLevel = append(nextLevel, node.Right)
			}
		}
		if len(nextLevel) == 0 {
			break
		}
		curLevel = nextLevel
	}

	return root
}

func stringToNode(data string) *TreeNode {
	if data == "null" {
		return nil
	}

	val, _ := strconv.Atoi(data)
	return &TreeNode{Val: val}
}

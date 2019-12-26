package _103_binary_tree_zigzag_level_order_traversal

import (
	"leetcode-golang/commons"
	"testing"
)

func TestZigzagLevelOrder(t *testing.T) {
	data := "[3,9,null,null,20,15,null,null,7,null,null]"
	tree := commons.Deserialize(data)

	res := zigzagLevelOrder(tree)
	want := [][]int{
		{3},
		{20,9},
		{15,7},
	}

	for i, levelWant := range res {
		if len(res) < i+1 {
			t.Errorf("get %d levels, want %d levels", len(res), len(want))
		}
		if !equal(res[i], levelWant) {
			t.Errorf("get %v for level %d, want %v", res[i], levelWant, i)
		}
	}
}

func equal(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}

	for i, val := range a {
		if val != b[i] {
			return false
		}
	}

	return true
}

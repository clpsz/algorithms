package _404_sum_of_left_leaves

import (
	. "leetcode-golang/commons"
	"testing"
)

func TestSumOfLeftLeaves(t *testing.T) {
	data1 := "[3,9,null,null,20,15,null,null,7,null,null]"
	tree1 := Deserialize(data1)
	res := sumOfLeftLeaves(tree1)
	want := 24
	if res != want {
		t.Errorf("get %d, want %d", res, want)
	}
}

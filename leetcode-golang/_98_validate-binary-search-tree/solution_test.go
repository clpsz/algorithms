package _98_validate_binary_search_tree

import (
	"leetcode-golang/commons"
	"testing"
)

func TestIsValidBST(t *testing.T){
	data1 := "[2,1,null,null,3,null,null]"
	tree1 := commons.Deserialize(data1)
	res := isValidBST(tree1)
	want := true
	if res != want {
		t.Errorf("get %t, want %t", res, want)
	}

	data2 := "[5,1,null,null,4,3,null,null,6,null,null]"
	tree2 := commons.Deserialize(data2)
	res = isValidBST(tree2)
	want = false
	if res != want {
		t.Errorf("get %t, want %t", res, want)
	}
}

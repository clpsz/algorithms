package _617_merge_two_binary_trees

import (
	. "leetcode-golang/commons"
	"testing"
)

func TestMergeTrees(t *testing.T) {
	data1 := "[1,3,5,null,null,null,2,null,null]"
	tree1 := Deserialize(data1)
	data2 := "[2,1,null,4,null,null,3,null,null]"
	tree2 := Deserialize(data2)
	tree3 := mergeTrees(tree1, tree2)
	want := "[3,4,5,null,null,4,null,null,5,null,null]"

	data3 :=  Serialize(tree3)
	if data3 != want {
		t.Errorf("get %s, want %s", data3, want)
	}
}

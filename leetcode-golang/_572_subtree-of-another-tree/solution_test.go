package _572_subtree_of_another_tree

import (
	. "leetcode-golang/commons"
	"testing"
)

func TestIsSubTree(t *testing.T) {
	data1 := "[3,4,1,null,null,2,null,null,5,null,null]"
	tree1 := Deserialize(data1)
	data2 := "[4,1,null,null,2,null,null]"
	tree2 := Deserialize(data2)
	res := isSubtree(tree1, tree2)
	want := true
	if res != want {
		t.Errorf("get %t, want %t", res, want)
	}
	data3 := "[4,1,null,null,3,null,null]"
	tree3 := Deserialize(data3)
	res = isSubtree(tree1, tree3)
	want = false
	if res != want {
		t.Errorf("get %t, want %t", res, want)
	}
}

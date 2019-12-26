package _00_99_recover_binary_search_tree

import (
	. "leetcode-golang/commons"
	"testing"
)

func TestMorrisTraverse(t *testing.T) {
	data := "[1,2,null,null,3,4,null,null,5,null,null]"
	tree := Deserialize(data)
	inOrderTraverseResult := inOrderTraverse(tree)
	var res = [5]int{}

	copy(res[:], inOrderTraverseResult)
	want := [...]int{2,1,4,3,5}
	if res != want {
		t.Errorf("get %v, want %v", res, want)

	}

	preOrderTraverseResult := preOrderTraverse(tree)
	copy(res[:], preOrderTraverseResult)
	want = [...]int{1,2,3,4,5}
	if res != want {
		t.Errorf("get %v, want %v", res, want)

	}
}

package _700_search_in_a_binary_search_tree

import (
	. "leetcode-golang/commons"
	"testing"
)

func TestMergeTrees(t *testing.T) {
	data1 := "[4,2,1,null,null,3,null,null,7,null,null]"
	tree1 := Deserialize(data1)
	res :=  Serialize(searchBST(tree1, 2))
	want := "[2,1,null,null,3,null,null]"
	if res != want {
		t.Errorf("get %s, want %s", res, want)
	}
}

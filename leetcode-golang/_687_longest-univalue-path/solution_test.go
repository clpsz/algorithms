package _687_longest_univalue_path

import (
	. "leetcode-golang/commons"
	"testing"
)

func TestLongestUnivaluePath(t *testing.T) {
	data := "[5,4,1,null,null,1,null,null,5,null,5,null,null]"
	tree := Deserialize(data)
	res := longestUnivaluePath(tree)
	want := 2
	if res != want {
		t.Errorf("get %d, want %d", res, want)
	}

	data2 := "[1,4,4,null,null,4,null,null,5,5,null,null,null]"
	tree2 := Deserialize(data2)
	res2 := longestUnivaluePath(tree2)
	want2 := 2
	if res2 != want2 {
		t.Errorf("get %d, want %d", res2, want2)
	}
}

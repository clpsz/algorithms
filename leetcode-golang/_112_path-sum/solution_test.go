package _112_path_sum

import (
	. "leetcode-golang/commons"
	"testing"
)

func TestHasPathSum(t *testing.T) {
	data := "[5,4,8,11,null,13,4,7,2,null,null,null,1]"
	tree := DeserializeLC(data)
	if hasPathSum(tree, 22) != true {
		t.Errorf("res %t, want %t", false, true)
	}

	data = "[1,2]"
	tree = DeserializeLC(data)

	if hasPathSum(tree, 1) == true {
		t.Errorf("res %t, want %t", false, true)
	}
}

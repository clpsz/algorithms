package _993_cousins_in_binary_tree

import (
	. "leetcode-golang/commons"
	"testing"
)

func TestIsCousins(t *testing.T) {
	if isCousins(DeserializeLC("[1,2,3,4]"), 3, 4) != false {
		t.Errorf("res %t, want %t", true, false)
	}
	if isCousins(DeserializeLC("[1,2,3,null,4,null,5]"), 5, 4) != true {
		t.Errorf("res %t, want %t", false, true)
	}
	if isCousins(DeserializeLC("[1,2,3,null,4]"), 2, 3) != false {
		t.Errorf("res %t, want %t", true, false)
	}
	if isCousins(DeserializeLC("[1,2,3,null,null,null,4,5]"), 1, 2) != false {
		t.Errorf("res %t, want %t", true, false)
	}
}


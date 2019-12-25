package _297_serialize_and_deserialize_binary_tree

import (
	. "leetcode-golang/commons"
	"testing"
)

func TestSerialize(t *testing.T) {
	/*
	     1
	    / \
	   2   3
	      / \
	     4   5
	*/
	var testData = []struct {
		Root       *TreeNode
		Serialized string
	}{
		{
			Root: &TreeNode{
				Val:  1,
				Left: &TreeNode{Val: 2},
				Right: &TreeNode{
					Val: 3,
					Left: &TreeNode{
						Val: 4,
					},
					Right: &TreeNode{
						Val: 5,
					},
				},
			},
			Serialized: "[1,2,null,null,3,4,null,null,5,null,null]",
		},
	}

	for _, data := range testData {
		res :=  Serialize(data.Root)
		want := data.Serialized
		if res != want {
			t.Errorf("serialize return %s, want %s", res, want)
		}
	}

}

func TestDeserialize(t *testing.T) {
	data := []string{
		"[1,2,null,null,3,4,null,null,5,null,null]",
		"[3,9,20,null,null,15,7,null,null,null,null]",
		"[]",
	}

	for _, s := range data {
		d := Deserialize(s)
		ss :=  Serialize(d)
		if ss != s {
			t.Errorf("don't match, serialize return %s, want %s", ss, s)
		}
	}
}

package commons

import "testing"

func TestSerializeLC(t *testing.T) {
	data := []struct{
		normal string
		leetcode string
	} {
		{"[1,null,null]", "[1]"},
		{"[1,2,null,null,3,null,null]", "[1,2,3]"},
		{"[1,2,null,null,3,4,null,null,5,null,null]", "[1,2,3,null,null,4,5]"},
	}

	for _, d := range data {
		tree := Deserialize(d.normal)
		res := SerializeLC(tree)
		if res != d.leetcode {
			t.Errorf("res %s, want %s", res, d.leetcode)
		}
	}
}

func TestDeserializeLC(t *testing.T) {
	data := []string{
		"[1]",
		"[1,2,3]",
		"[1,2,3,null,null,4,5]",
		"[1,3,null,null,4]",
	}

	for _, d := range data {
		if d != SerializeLC(DeserializeLC(d)) {
			t.Errorf("res %s, want %s", SerializeLC(DeserializeLC(d)), d)
		}
	}
}

package _606_construct_string_from_binary_tree

import (
	. "leetcode-golang/commons"
	"testing"
)

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func TestTree2str(t *testing.T) {
	res := tree2str(DeserializeLC("[1,2,3,4]"))
	want := "1(2(4))(3)"
	if res != want {
		t.Errorf("got %s, want %s", res, want)
	}
	res = tree2str(DeserializeLC("[1,2,3,null,4]"))
	want = "1(2()(4))(3)"
	if res != want {
		t.Errorf("got %s, want %s", res, want)
	}
}

package _105_construct_binary_tree_from_preorder_and_inorder_traversal

import (
	"leetcode-golang/commons"
	"testing"
)

func TestBuildTree(t *testing.T) {
	preOrder := []int{3,9,20,15,7}
	inOrder := []int{9,3,15,20,7}

	tree := buildTree(preOrder, inOrder)
	treeS := commons.SerializeLC(tree)
	want := "[3,9,20,null,null,15,7]"

	if treeS != want {
		t.Errorf("res %s, want %s", treeS, want)
	}
}

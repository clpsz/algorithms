package _95_unique_binary_search_trees_ii

import (
	. "leetcode-golang/commons"
	"testing"
)

func TestGenerateTrees(t *testing.T){
	n := 3
	trees := generateTrees(n)

	for _, t := range trees {
		println(Serialize(t))
	}
}

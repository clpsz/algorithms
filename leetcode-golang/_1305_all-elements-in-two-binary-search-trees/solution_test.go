package _1305_all_elements_in_two_binary_search_trees

import (
	"github.com/stretchr/testify/assert"
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
func TestGetAllElements(t *testing.T) {
	cases := []struct{
		t1, t2 string
		want []int
	} {
		{"[2,1,4]", "[0,1,3]", []int{0,1,1,2,3,4}},
	}

	for _, c := range cases {
		res := getAllElements(DeserializeLC(c.t1), DeserializeLC(c.t2))
		assert.ElementsMatch(t, res, c.want)
	}
}

package _501_find_mode_in_binary_search_tree

import (
	. "leetcode-golang/commons"
	"sort"
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

func TestFindMode(t *testing.T) {
	cases := []struct {
		input string
		want []int
	}{
		{"[]", []int{}},
		{"[1]", []int{1}},
		{"[1,null,2,2]", []int{2}},
		{"[1,null,2]", []int{1, 2}},
	}

	for _, c := range cases {
		r := findMode(DeserializeLC(c.input))
		sort.Ints(r)
		for i, e := range r {
			if i >= len(c.want) || e != c.want[i] {
				t.Errorf("input %s, got %v, want %v", c.input, r, c.want)
				break
			}
		}
	}
}

package _283_move_zeroes

import (
	"fmt"
	"testing"
)

func TestMoveZeroes(t *testing.T) {
	nums := []int{0,1,0,3,12}
	moveZeroes(nums)
	fmt.Println(nums)

	nums = []int{2,1}
	moveZeroes(nums)
	fmt.Println(nums)
}
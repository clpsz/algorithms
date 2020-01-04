package _283_move_zeroes

func moveZeroes(nums []int) {
	for i, j := 0, 0; j < len(nums); j++ {
		if nums[j] != 0 {
			nums[i] = nums[j]
			if j != i {
				nums[j] = 0
			}
			i++
		}
	}
}

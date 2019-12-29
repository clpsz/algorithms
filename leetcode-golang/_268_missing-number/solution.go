package _268_missing_number

func missingNumber(nums []int) int {
	nums = append(nums, -1)
	for i := 0; i < len(nums); {
		e := nums[i]
		if e >= 0 && e != i {
			nums[e], nums[i] = nums[i], nums[e]
		} else {
			i++
		}
	}

	for i, e := range nums {
		if e == -1 {
			return i
		}
	}

	return -1 // should never reach
}

package _1306_jump_game_iii

func canReach(arr []int, start int) bool {
	if len(arr) == 0 {
		return false
	}

	seen := make(map[int]bool)
	currentLoop := []int{start}

	for {
		if len(currentLoop) == 0 {
			break
		}

		nextLoop := make([]int, 0)
		for _, e := range currentLoop {
			if e < 0 || e >= len(arr) {
				seen[e] = true
				continue
			}
			if seen[e] {
				continue
			}
			if arr[e] == 0 {
				return true
			}
			seen[e] = true

			nextLoop = append(nextLoop, e-arr[e], e+arr[e])
		}
		currentLoop = nextLoop
	}

	return false
}

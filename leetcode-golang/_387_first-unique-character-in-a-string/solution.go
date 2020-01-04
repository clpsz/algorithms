package _387_first_unique_character_in_a_string

func firstUniqChar(s string) int {
	countAndIndex := make(map[rune]struct{
		count int
		index int
	})
	for i, r := range s {
		cni := countAndIndex[r]
		cni.count++
		if cni.count == 1 {
			cni.index = i
		}
		countAndIndex[r] = cni
	}

	minIndex := -1
	for _, v := range countAndIndex {
		if v.count == 1 {
			if minIndex == -1 {
				minIndex = v.index
			} else if v.index < minIndex {
				minIndex = v.index
			}
		}
	}

	return minIndex
}

package _242_valid_anagram

func isAnagram(s string, t string) bool {
	sCount, tCount := [26]int{}, [26]int{}

	if len(s) != len(t) {
		return false
	}

	for _, r := range s {
		sCount[r-'a']++
	}
	for _, r := range t {
		tCount[r-'a']++
	}

	return sCount == tCount
}

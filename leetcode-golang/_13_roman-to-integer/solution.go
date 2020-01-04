package _13_roman_to_integer

/*
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/

func romanToInt(s string) int {
	mapping := map[rune]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}

	var res int

	var pre, cur rune
	for _, cur = range s {
		if pre != 0 && mapping[cur] > mapping[pre] {
			res -= mapping[pre]
		} else {
			res += mapping[pre]
		}
		pre = cur
	}

	res += mapping[pre]

	return res
}

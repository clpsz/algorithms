package _13_roman_to_integer

import "testing"

func TestRomanToInt(t *testing.T) {
	cases := []struct{
		input string
		want int
	} {
		{"III", 3},
		{"IV", 4},
		{"IX", 9},
		{"LVIII", 58},
		{"MCMXCIV", 1994},
	}

	for _, c := range cases {
		if romanToInt(c.input) != c.want {
			t.Errorf("input %s, got %d, want %d", c.input, romanToInt(c.input), c.want)
		}
	}
}

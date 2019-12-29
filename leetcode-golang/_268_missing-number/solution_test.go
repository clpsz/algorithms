package _268_missing_number

import "testing"

func TestMissingNumber(t *testing.T) {
	cases := []struct{
		input [] int
		want int
	} {
		{[]int{9,6,4,2,3,5,7,0,1}, 8},
	}
	for _, c := range cases {
		r := missingNumber(c.input)
		if r != c.want {
			t.Errorf("input %v, got %d, want %d", c.input, r, c.want)
		}
	}
}

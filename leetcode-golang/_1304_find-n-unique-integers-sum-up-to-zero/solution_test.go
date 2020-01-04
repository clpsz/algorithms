package _1304_find_n_unique_integers_sum_up_to_zero

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestSumZero(t *testing.T) {
	res1 := sumZero(1)
	assert.ElementsMatch(t, res1, []int{0})

	res2 := sumZero(5)
	for _, e := range res2 {
		println(e)
	}
}

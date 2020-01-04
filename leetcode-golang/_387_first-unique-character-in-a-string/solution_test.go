package _387_first_unique_character_in_a_string

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestFirstUniqChar(t *testing.T) {
	assert.Equal(t, firstUniqChar("leetcode"), int(0))
	assert.Equal(t, firstUniqChar("loveleetcode"), int(2))
}

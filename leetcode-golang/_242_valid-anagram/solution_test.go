package _242_valid_anagram

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestIsAnagram(t *testing.T) {
	s1, t1 := "anagram", "nagaram"
	assert.Equal(t, isAnagram(s1, t1), true, "should be true")
	s2, t2 := "car", "art"
	assert.Equal(t, isAnagram(s2, t2), false, "should be false")
}

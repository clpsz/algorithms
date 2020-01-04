package _1306_jump_game_iii

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestCanReach(t *testing.T) {
	assert.True(t, canReach([]int{4,2,3,0,3,1,2}, 5))
}

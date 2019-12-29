package _155_min_stack

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func TestMinStack(t *testing.T) {
	stack := Constructor()
	stack.Push(-2)
	stack.Push(0)
	stack.Push(-3)
	assert.Equal(t, -3, stack.GetMin())
	stack.Pop()
	assert.Equal(t, -2, stack.GetMin())
}

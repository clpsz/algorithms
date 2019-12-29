package _155_min_stack

type MinStack1 struct {
	stack []int
	min   []int
}

/** initialize your data structure here. */
func Constructor1() MinStack1 {
	return MinStack1{}
}

func (this *MinStack1) Push(x int) {
	this.stack = append(this.stack, x)
	if len(this.min) > 0 {
		if x <= this.min[len(this.min)-1] {
			this.min = append(this.min, x)
		}
	} else {
		this.min = append(this.min, x)
	}
}

func (this *MinStack1) Pop() {
	top := this.Top()
	this.stack = this.stack[:len(this.stack)-1]
	curMin := this.min[len(this.min)-1]
	if top == curMin {
		this.min = this.min[:len(this.min)-1]
	}
}

func (this *MinStack1) Top() int {
	return this.stack[len(this.stack)-1]
}

func (this *MinStack1) GetMin() int {
	return this.min[len(this.min)-1]
}

/**
 * Your MinStack1 object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */

func minOperations(nums []int, k int) int {
	numbers := Numbers(nums)
	ptrNumbers := &numbers
	heap.Init(ptrNumbers)

	operations := 0

	for numbers.Len() > 1 {
		if numbers[0] >= k {
			break
		}
		f := heap.Pop(ptrNumbers).(int)
        s := numbers[0]

        numbers[0]=min(f, s)*2+max(f, s)
        heap.Fix(ptrNumbers,0)
		
		operations++
	}

	return operations
}

type Numbers []int

func (n Numbers) Len() int           { return len(n) }
func (n Numbers) Swap(i, j int)      { n[i], n[j] = n[j], n[i] }
func (n Numbers) Less(i, j int) bool { return n[i] < n[j] }
func (n *Numbers) Push(obj any)      { *n = append(*n, obj.(int)) }
func (n *Numbers) Pop() any {
	old := *n
	lenght := len(old)
	elem := old[lenght-1]
	*n = old[:lenght-1]
	return elem
}
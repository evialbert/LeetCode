func gcd(a, b int) int {
	for b != 0 {
		a, b = b, a%b
	}
	return a
}

func replaceNonCoprimes(nums []int) []int {
    // Initialize cap to reduce allocation overhead
	stack := make([]int, 0, len(nums))

	for _, num := range nums {
		stack = append(stack, num) // push new value

		// keep merging until gcd = 1
		for len(stack) > 1 {
			n := len(stack)
			g := gcd(stack[n-1], stack[n-2]) 
            if g == 1 {
				break
			}

			stack[n-2] = stack[n-1] / g * stack[n-2] // compute lcm
			stack = stack[:n-1] // pop
		}
	}
	return stack
}
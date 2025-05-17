func sortColors(nums []int) {
    count := [3]int{0, 0, 0}
    for _, num := range nums {
        count[num]++
    }
    idx := 0
    for i := 0; i < 3; i++ {
        for j := 0; j < count[i]; j++ {
            nums[idx] = i
            idx++
        }
    }
}
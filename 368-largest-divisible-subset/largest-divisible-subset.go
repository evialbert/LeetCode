func largestDivisibleSubset(nums []int) []int {
    answer := make([][]int, len(nums))
    idx := 0
    sort.Ints(nums)
    for i := range nums {
        _max, _idx := 0, 0
        for j:=0; j<i; j++ {
            if nums[i] % nums[j] == 0 && _max < len(answer[j]) {
                _max = len(answer[j])
                _idx = j
            }
        }
        if _max != 0 {
            answer[i] = append(append([]int{}, answer[_idx]...), nums[i])
        } else {
            answer[i] = []int{nums[i]}
        }
        if len(answer[i]) > len(answer[idx]) {
            idx = i
        }
    }
    return answer[idx]
}       
class Solution {
    func longestMonotonicSubarray(_ nums: [Int]) -> Int {
        var mx = 0
        var pre = 0
        var count = 0

        for num in nums {
            count = 1 + (pre == 0 || num <= pre ? 0 : count)
            mx = max(mx, count)
            pre = num
        }

        pre = 0
        for num in nums {
            count = 1 + (pre == 0 || num >= pre ? 0 : count)
            mx = max(mx, count)
            pre = num
        }

        return mx
    }
}
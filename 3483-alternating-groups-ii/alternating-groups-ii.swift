class Solution {
    func numberOfAlternatingGroups(_ colors: [Int], _ k: Int) -> Int {
        var arr =  colors + colors
        var ans = 0
        let n = colors.count
        var dp = Array(repeating: 1, count: 2 * n)
        
        for i in 1..<2 * n {
            if arr[i - 1] != arr[i] {
                dp[i] = dp[i - 1] + 1
            }
        }
        
        for i in 0..<n{
            if dp[i] >= k || dp[i + n] >= k{
                ans += 1
            }
        }
        
        return ans
    }
}
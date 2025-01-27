class Solution {
    func lexicographicallySmallestArray(_ nums: [Int], _ limit: Int) -> [Int] {
        var ans = Array(repeating: 0, count: nums.count)
        let arr = nums.enumerated().sorted { $0.1 < $1.1 }
        
        var left = 0
        
        while left < nums.count {
            var right = left + 1
            
            while right < nums.count && arr[right].1 - arr[right - 1].1 <= limit {
                right += 1
            }
            
            let temp_ind = arr[left..<right].map{$0.0}.sorted()
            let temp_val = arr[left..<right].map{ $0.1}
           
            for i in 0..<temp_ind.count {
                ans[temp_ind[i]] = temp_val[i]
            }
            
            left = right
        }
        
        return ans
    }
}
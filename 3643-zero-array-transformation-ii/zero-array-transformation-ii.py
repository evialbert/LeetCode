class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        left = 0
        right = len(queries)
        result = -1
        
        while left <= right:
            mid = (left + right) // 2
            if self.canZeroArray(nums, queries, mid):
                result = mid
                right = mid - 1
                
            else:
                left = mid + 1
                
        return result
    
    def canZeroArray(self, nums, queries, k):
        n = len(nums)
        diff = [0] * (n + 1)
        
        for i in range(k):
            l, r, val = queries[i]
            diff[l] -= val
            diff[r + 1] += val
            
        currentDecrement = 0
        for i in range(n):
            currentDecrement += diff[i]
            if nums[i] + currentDecrement > 0:
                return False
            
        return True        
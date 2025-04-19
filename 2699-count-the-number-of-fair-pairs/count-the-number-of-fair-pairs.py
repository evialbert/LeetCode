class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        n = len(nums)
        nums.sort()
        count = 0
        
        for i, x in enumerate(nums):
            loVal = lower - x
            hiVal = upper - x
            left = bisect.bisect_left(nums, loVal, i + 1, n)
            right = bisect.bisect_right(nums, hiVal, i + 1, n)            
            count += (right - left)
        
        return count        
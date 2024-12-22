class Solution:
    def buttonWithLongestTime(self, nums: List[List[int]]) -> int:
        index, maxTime = nums[0][0], nums[0][1]
        
        for i in range(1, len(nums)):
            newTime = nums[i][1] - nums[i-1][1]
            if maxTime <= newTime:
                index, maxTime = nums[i][0] if maxTime < newTime else min(nums[i][0], index), newTime
        return index
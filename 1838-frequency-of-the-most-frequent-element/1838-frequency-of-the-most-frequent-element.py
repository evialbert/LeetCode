class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        windowStart = windowEnd = len(nums) - 1
        area = 0

        while windowStart:
            windowStart -= 1
            area += nums[windowEnd] - nums[windowStart]
            if k < area:
                diff = nums[windowEnd] - nums[windowEnd-1]
                area -= diff * (windowEnd - windowStart)
                windowEnd -= 1
        return windowEnd - windowStart + 1
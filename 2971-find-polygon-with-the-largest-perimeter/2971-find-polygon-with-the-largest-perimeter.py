# Time complexity: O(N log N)
# Space complexity: O(1)
class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        l: int = -1
        s: int = sum(nums[:2])
        for i in range(2, len(nums)):
            if nums[i] < s:
                l = nums[i] + s
            s += nums[i]
        return l
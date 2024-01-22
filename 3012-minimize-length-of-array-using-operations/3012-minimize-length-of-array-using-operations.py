class Solution:
    def minimumArrayLength(self, nums: List[int]) -> int:
        v = min(nums)
        return 1 if any(u % v > 0 for u in nums) else (nums.count(v) + 1) // 2
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums) <= 1:
            return True
        
        max_idx = 0
        for i, num in enumerate(nums):
            if i > max_idx:
                return False
            max_idx = max(max_idx, i+num)
        
        return max_idx >= len(nums)-1
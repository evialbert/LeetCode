class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        max_len = 1
        
        for i in range(len(nums) -1):
            curr_len = 1
            while i < len(nums) -1 and nums[i] < nums[i + 1]:
                curr_len += 1
                i += 1
            max_len = max(max_len, curr_len)
            
        for i in range(len(nums) -2, -1, -1):
            curr_len = 1
            while i >= 0 and nums[i] > nums[i + 1]:
                curr_len += 1
                i -= 1
            max_len = max(max_len, curr_len)
        
        return max_len
class Solution:
    def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
        ans = len(nums)+1
        for i in range(len(nums)):
            temp = 0
            for j in range(i, len(nums)):
                temp = temp | nums[j]
                
                if temp >= k:
                    ans = min(j-i+1, ans)
            
        if ans > len(nums):
            return -1
        
        return ans
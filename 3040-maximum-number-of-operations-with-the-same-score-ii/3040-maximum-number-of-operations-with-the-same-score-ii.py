class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        
        @cache
        def calc(i, j, s):     
            if (j-i) < 1:
                return 0
            ans = 0
            if nums[i] + nums[i+1] == s:
                ans = max(ans, calc(i+2, j, s) + 1)
            if nums[j] + nums[j-1] == s:
                ans = max(ans, calc(i, j-2, s) + 1)
            if nums[i] + nums[j] == s:
                ans = max(ans, calc(i+1, j-1, s) + 1)
            
            return ans
        return 1+max(calc(2, len(nums)-1, nums[0]+nums[1]), calc(0, len(nums)-3, nums[-1]+nums[-2]), calc(1, len(nums)-2, nums[0]+nums[-1]))
    
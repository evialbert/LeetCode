class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [-1 for _ in range(n+1)]

        def result(idx):
            if idx == 0:
                return nums[idx]
            if idx < 0:
                return 0
            if dp[idx] != -1:
                return dp[idx]
            
            pick = nums[idx] + result(idx-2)
            notPick = result(idx-1)
            dp[idx] = max(pick,notPick)
            
            return dp[idx]
        
        return result(n-1)
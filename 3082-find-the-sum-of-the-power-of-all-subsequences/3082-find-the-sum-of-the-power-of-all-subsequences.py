class Solution:
    def sumOfPower(self, nums, k):
        n, mod = len(nums), 10**9+7  

        @lru_cache(None)
        def dfs(i,length,total):
            if total == k:
                return pow(2,n-length,mod)

            if i >= n or total > k:
                return 0 

            return (dfs(i+1,length+1,total+nums[i])%mod + dfs(i+1,length,total)%mod)%mod

        return dfs(0,0,0)%mod
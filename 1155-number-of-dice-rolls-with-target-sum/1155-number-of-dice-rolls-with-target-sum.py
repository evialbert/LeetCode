class Solution:
    def fun(self,n,k,target,dp):
        if n==0 and target==0:
            return 1
        if n==0:
            return 0  
        if dp[n][target]!=-1:
            return dp[n][target]  
        ans=0
        for i in range(1,k+1):
            if target-i>=0:
                ans+=self.fun(n-1,k,target-i,dp)
        dp[n][target]=ans%(10**9 +7)
        return dp[n][target]
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
       dp=[[-1]*(target+1) for i in range(n+1)]
       return self.fun(n,k,target,dp)
class Solution:
    def minArraySum(self, nums: List[int], k: int, op1: int, op2: int) -> int:
        n = len(nums)
        dp = [[[0 for k in range(n+1)] for i in range(n+1)] for j in range(n+1)]
        for i in range(1,n+1):
            for o1 in range(op1+1):
                for o2 in range(op2+1):
                    minn = dp[i-1][o1][o2] + nums[i-1]
                    if o1>0:
                        minn = min(
                            minn,
                            dp[i-1][o1-1][o2] + ceil(nums[i-1]/2)
                        )
                    if o2>0 and nums[i-1] >= k:
                        minn = min(
                            minn, 
                            dp[i-1][o1][o2-1]+nums[i-1]-k,
                        )
                    if o1>0 and o2>0 and ceil(nums[i-1]/2)>=k:
                        minn = min(
                            minn, 
                            dp[i-1][o1-1][o2-1]+ceil(nums[i-1]/2)-k
                        )
                    if o1>0 and o2>0 and nums[i-1]>=k:
                        minn = min(
                            minn, 
                            dp[i-1][o1-1][o2-1]+ceil((nums[i-1]-k)/2)
                        )

                    dp[i][o1][o2] = minn
        return dp[n][op1][op2]
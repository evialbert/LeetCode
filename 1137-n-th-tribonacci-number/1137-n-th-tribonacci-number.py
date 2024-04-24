class Solution:
    def tribonacci(self, n: int) -> int:

        # use hashmap for constant lookup memoization
        dp = collections.defaultdict(int)
        dp[0], dp[1], dp[2] = 0, 1, 1 #init first three values given by problem statement

        # iterate over given range (3 -> n) to find the nth value of the sequence
        for i in range(3, n+1):
            # utilizes the memoization as we have already calulcated the previous three values
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3]

        return dp[n] # return nth number in the sequence

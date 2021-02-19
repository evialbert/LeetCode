class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        n = len(triangle)
        dp = triangle[-1]
        for layer in range(n - 2, -1, -1):
            for i in range(layer + 1):
                dp[i] = min(dp[i], dp[i + 1]) + triangle[layer][i]
        return dp[0]
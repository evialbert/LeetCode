class Solution:
    # @param {integer[][]} dungeon
    # @return {integer}
    def calculateMinimumHP(self, dungeon):
        M = len(dungeon)
        N = len(dungeon[0])
        dp = []
        for _ in range(M):
            dp.append([0] * N)
            
        for i in range(M - 1, -1, -1):
            for j in range(N - 1, -1, -1):
                if i == M - 1 and j == N - 1:
                    dp[i][j] = max(1, 1 - dungeon[i][j])
                elif i == M - 1:
                    right = dp[i][j + 1]
                    dp[i][j] = max(1, right - dungeon[i][j])
                elif j == N - 1:
                    down = dp[i + 1][j]
                    dp[i][j] = max(1, down - dungeon[i][j])
                else:
                    right = dp[i][j + 1]
                    down = dp[i + 1][j]
                    dp[i][j] = min(max(1, right - dungeon[i][j]), max(1, down - dungeon[i][j]))
        return dp[0][0]
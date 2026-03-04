class Solution:
    def numberOfRoutes(self, grid: List[str], d: int) -> int:
        MOD = 10**9 + 7
        n = len(grid)
        m = len(grid[0])

        def calculate(newdp, prefix_dp, r):
            for i in range(1, m):
                newdp[i] = (newdp[i] + newdp[i-1])%MOD

            for i in range(m):
                if grid[r][i] == '#':
                    pre_dp[i] = 0
                    continue
                left = 0  if i - d - 1 < 0 else newdp[i-d-1]
                pre_dp[i] = newdp[min(m-1, i+d)] - left

            # Prefix sum for faster calculations
            for i in range(1, m):
                pre_dp[i] = (pre_dp[i] + pre_dp[i-1])%MOD
        
        newdp = [1 if x == '.' else 0 for x in grid[0]]
        pre_dp = [0]*m
        calculate(newdp, pre_dp, 0)
        # FOR JUMP
        # d = sqrt((1)^2 + (c1-c2)^2) -> d = sqrt(1 + x^2) -> x = sqrt(d^2 - 1)
        r = int(sqrt(pow(d, 2) - 1)) 

        for i in range(1, n):
            newdp = []
            for j in range(m):
                if grid[i][j] == '#': 
                    newdp.append(0)
                    continue
                left = 0 if j-r-1 < 0 else pre_dp[j-r-1]
                newdp.append(pre_dp[min(m-1, j+r)] - left)
            calculate(newdp, pre_dp, i)
        return pre_dp[-1]
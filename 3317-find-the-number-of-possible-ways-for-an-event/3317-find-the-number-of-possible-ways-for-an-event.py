class Solution:
    def numberOfWays(self, n: int, x: int, y: int) -> int:
        pow_y = [1] * (x + 1)
        m = (10 ** 9) + 7
        for i in range(1, x + 1):
            pow_y[i] = (y * pow_y[i - 1]) % m
        dp = [0] * (x + 1)
        dp[1] = x
        ans = 0
        for i in range(1, n):
            temp = [0] * (x + 1)
            for j in range(1, x + 1):
                filled = dp[j]
                rem = x - j
                temp[j] = (temp[j] + (filled * j)) % m
                if j + 1 <= x:temp[j + 1] = (temp[j + 1] + (filled * rem)) % m
            dp = temp
        for i in range(1, x + 1):
            ans = (ans + (dp[i] * (pow_y[i]))) % m
        return ans
        
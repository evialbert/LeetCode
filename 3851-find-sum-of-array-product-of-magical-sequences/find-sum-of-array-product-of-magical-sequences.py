class Solution:
    def magicalSum(self, M: int, K: int, nums: List[int]) -> int:
        MOD = 10**9 + 7
        n = len(nums)

        f = [1 for _ in range(M + 1)]
        inverse_f = [1 for _ in range(M + 1)]
        for i in range(1, M + 1):
            f[i] = f[i - 1] * i % MOD

        inverse_f[M] = pow(f[M], MOD - 2, MOD)
        for i in range(M, 0, -1):
            inverse_f[i - 1] = inverse_f[i] * i % MOD

        pow_nums = [[1 for _ in range(M + 1)] for _ in range(n)]
        for i in range(n):
            for c in range(1, M + 1):
                pow_nums[i][c] = pow_nums[i][c - 1] * nums[i] % MOD

        dp = [[[[0 for _ in range(M + 1)] for _ in range(K + 1)] for _ in range(M + 1)] for _ in range(n + 1)]
        dp[0][0][0][0] = 1
        for i in range(n):
            for m1 in range(M + 1):
                for k in range(K + 1):
                    for m2 in range(M + 1):
                        val = dp[i][m1][k][m2]

                        if not val:
                            continue

                        for c in range(M - m1 + 1):
                            m12 = m1 + c
                            s = c + m2
                            bit = s & 1
                            k2 = k + bit
                            if k2 > K:
                                continue
                            m22 = s >> 1
                            dp[i + 1][m12][k2][m22] += val * inverse_f[c] % MOD * pow_nums[i][c] % MOD
                            dp[i + 1][m12][k2][m22] %= MOD

        ans = 0
        for k in range(K + 1):
            for m2 in range(M + 1):
                val = dp[n][M][k][m2]
                if not val:
                    continue
                bits = bin(m2).count('1')
                if k + bits == K:
                    ans += val
                    ans %= MOD

        ans = ans * f[M] % MOD
        return ans
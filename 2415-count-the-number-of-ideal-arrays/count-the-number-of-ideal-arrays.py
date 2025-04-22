class Solution:
    def idealArrays(self, n: int, maxValue: int) -> int:
        MOD = int(1e9 + 7)
        ans = 0
        for k in range(1, maxValue + 1):
            factors = self.allFactors(k)
            cur = 1
            for f in factors:
                cur *= sum(math.comb(n - 1 + i - 1, i) for i in range(factors[f] + 1))
            ans = (ans + cur) % MOD
        return ans

    def allFactors(self, k):
        factors = defaultdict(int)
        f = 2
        while f * f <= k:
            if k % f == 0:
                factors[f] += 1
                k //= f
            else:
                f += 1
        if k > 1:
            factors[k] += 1
        return factors
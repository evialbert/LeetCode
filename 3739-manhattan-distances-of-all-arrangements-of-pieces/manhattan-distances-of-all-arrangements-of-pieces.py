class Solution:
    def distanceSum(self, m: int, n: int, k: int) -> int:
        return (((n * n) * (m - 1) * m * (m + 1) // 6)+((m * m) * (n - 1) * n * (n + 1) // 6)%(10**9+7))*(comb(n*m-2,k-2)%(10**9+7))%(10**9+7)
        
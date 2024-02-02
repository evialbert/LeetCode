class Solution:
    def sumSubseqWidths(self, nums: List[int]) -> int:
        MOD = 1_000_000_007
        ans = 0 
        for i, x in enumerate(sorted(nums)): 
            ans += x * (pow(2, i, MOD) - pow(2, len(nums)-i-1, MOD))
        return ans % MOD
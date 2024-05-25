class Solution:
    def sumDigitDifferences(self, nums: List[int]) -> int:
        cnt = defaultdict(Counter)
        ans = 0
        for i, v in enumerate(nums):
            for j, c in enumerate(str(v)):
                ans += i - cnt[j][c]
                cnt[j][c] += 1
        return ans
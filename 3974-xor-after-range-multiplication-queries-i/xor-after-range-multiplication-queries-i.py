class Solution:
    def xorAfterQueries(self, nums: list[int], queries: list[list[int]]) -> int:
        for l, r, k, v in queries:
            i = l
            while i <= r:
                nums[i] = (nums[i] * v) % (10**9+7)
                i += k
        x = 0
        for a in nums:
            x ^= a
        return x
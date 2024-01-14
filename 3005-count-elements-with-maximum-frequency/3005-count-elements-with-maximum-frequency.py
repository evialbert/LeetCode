class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        freq = Counter(nums)
        maxi = 0
        res = 0
        for v in freq.values():
            maxi = max(maxi, v)
        for v in freq.values():
            if v == maxi:
                res += v
        return res
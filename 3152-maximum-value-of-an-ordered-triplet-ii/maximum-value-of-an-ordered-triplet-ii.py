class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
      res = maxDiff = maxVal = 0

      for n in nums:
        res = max(res, maxDiff * n)
        maxDiff = max(maxDiff, maxVal - n)
        maxVal = max(maxVal, n)

      return res
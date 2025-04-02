class Solution:
    def maximumTripletValue(self, nums: List[int]) -> int:
        ans, max_sub, max_n = 0, 0, 0
        for n in nums:
            ans = max(max_sub * n, ans)
            max_sub = max(max_n - n, max_sub)
            max_n = max(n, max_n)
        return ans
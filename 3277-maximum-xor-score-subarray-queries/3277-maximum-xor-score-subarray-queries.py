class Solution:
    def maximumSubarrayXor(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums)
        scores = [[0] * (n+1) for _ in range(n+1)]
        ans = [[0] * (n+1) for _ in range(n+1)]
        for i in range(n):
            scores[i][i+1] = ans[i][i+1] = nums[i]
        for l in range(2, n+1):
            for i in range(n-l+1):
                scores[i][i+l] = scores[i][i+l-1] ^ scores[i+1][i+l]
                ans[i][i+l] = max(scores[i][i+l], ans[i][i+l-1], ans[i+1][i+l])
        return [ans[l][r+1] for l, r in queries]
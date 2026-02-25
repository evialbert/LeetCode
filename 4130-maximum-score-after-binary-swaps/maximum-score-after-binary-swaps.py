class Solution:
    def maximumScore(self, nums: List[int], s: str) -> int:
        numHeap = []
        res = 0
        for i, num in enumerate(nums):
            heapq.heappush(numHeap, -num)
            if s[i] == '1':
                res -= heapq.heappop(numHeap)
        return res
                
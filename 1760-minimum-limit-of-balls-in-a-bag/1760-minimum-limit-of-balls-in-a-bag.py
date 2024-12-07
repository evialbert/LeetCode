class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        lo, hi = 1, 1_000_000_000
        while lo < hi: 
            mid = lo + hi >> 1
            if sum((x-1)//mid for x in nums) <= maxOperations: hi = mid
            else: lo = mid + 1
        return lo
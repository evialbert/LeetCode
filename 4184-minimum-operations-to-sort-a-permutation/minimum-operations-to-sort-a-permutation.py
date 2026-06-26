class Solution:
    def minOperations(self, nums: List[int]) -> int:

        n, beg = len(nums), nums.index(0)
        end = n - beg

        for idx in range(n):
            if nums[(beg + idx) % n] != idx: break
        else: 
            return beg if beg < end + 2 else end + 2

        for idx in range(n):
            if nums[(beg - idx) % n] != idx: break
        else: 
            return end if end < beg + 2 else beg + 2
            
        return -1
        
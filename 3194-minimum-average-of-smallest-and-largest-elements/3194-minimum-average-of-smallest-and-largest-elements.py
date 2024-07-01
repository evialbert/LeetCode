class Solution:
    def minimumAverage(self, nums: List[int]) -> float:
        a = len(nums)//2
        c = []
        for i in range(a):
            m = max(nums)
            n = min(nums)
            c.append((m+n)/2)
            nums.remove(m)
            nums.remove(n)
        return min(c)  
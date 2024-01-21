class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        c = defaultdict(int)
        for i in nums[1:]:
            c[i] += 1
        a = min(c)
        c[a] -= 1
        if c[a] == 0:
            del c[a]
            b = min(c)
            c[b] -= 1
        else:
            b = min(c)
        return nums[0] + a + b
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        m = {}
        for i in range(len(nums)):
            for n in nums[i]:
                if not n in m:
                    m[n] = set()
                m[n].add(i)
        lst = list(m.keys())
        lst.sort()
        mm = {}
        res = lst[-1] - lst[0]+1
        rng = []
        for i in range(len(lst)):
            val = lst[i]
            for v in m[val]:
                mm[v] = val
            minVal = min(mm.values())
            if len(mm) == len(nums) and val - minVal < res:
                rng = [minVal, val]
                res = val - minVal
        return rng
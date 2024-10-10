class Solution:
    def gcdValues(self, nums: List[int], queries: List[int]) -> List[int]:
        maxv=max(nums)
        co,lcount = [0]*(maxv+1), [0]*(maxv+1)
        for v in nums: co[v]+=1
        for i in range(1, maxv+1):
            x = 0
            for mul in range(i, maxv+1, i): x+=co[mul]
            lcount[i]=x*(x-1)//2
        for i in range(maxv, 0, -1):
            for mul in range(2*i, maxv+1, i): lcount[i] -= lcount[mul]
        acc=list(accumulate(lcount))
        return [bisect.bisect_right(acc, q) for q in queries]
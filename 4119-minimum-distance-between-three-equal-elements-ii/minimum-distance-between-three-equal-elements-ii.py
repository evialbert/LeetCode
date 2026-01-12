class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        d=defaultdict(list)
        for i in range(len(nums)):
            d[nums[i]].append(i)
        s=float('inf')
        if all(len(i)<3 for i in d.values()):
            return -1
        for i in d.values():
            if len(i)>2:
                i.sort()
                for j in range(len(i)-2):
                     a,b,c=i[j],i[j+1],i[j+2]
                     c=abs(a-b)+abs(b-c)+abs(a-c)
                     s=min(s,c)
        return s
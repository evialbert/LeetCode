class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        arr=set(nums)
        c=[]
        for i in arr:
            a=nums.count(i)
            l=[i,a]
            c.append(l)
        sa=sorted(c, key=lambda x : x[1])
        return sa[-1][0]
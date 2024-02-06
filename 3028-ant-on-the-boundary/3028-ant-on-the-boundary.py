class Solution:
    def returnToBoundaryCount(self, nums: List[int]) -> int:
        s=0
        c=0
        for i in nums:
            s+=i
            if(s==0):
                c+=1
        return c
class Solution:
    def maxOperations(self, nums: List[int]) -> int:
        res=1
        s=nums[0]+nums[1]
        for i in range(2,len(nums)-1,2):
            if nums[i]+nums[i+1]==s:
                res+=1
            else:
                break
        return res
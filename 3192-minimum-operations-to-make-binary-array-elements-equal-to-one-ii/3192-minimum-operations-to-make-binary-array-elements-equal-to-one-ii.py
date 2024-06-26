class Solution:
    def minOperations(self, nums: List[int]) -> int:
        flag=0
        ans=0
        for i in range(len(nums)):
            if(nums[i]==flag):
                ans+=1
                flag=1-nums[i]
        return ans
class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        s,n=0,len(nums)
        rm,mini=[],nums[-1]
        for i in range(n-1,-1,-1):
            rm.append(mini)
            if nums[i]<mini:
                mini=nums[i]
        mini,ans=nums[0],float('inf')
        for i in range(1,n-1):
            if nums[i]>mini and nums[i]>rm[n-1-i]:
                ans=min(ans,mini+nums[i]+rm[n-1-i])
            if nums[i]<mini:
                mini=nums[i]
        if ans==float('inf'):
            return -1
        return ans
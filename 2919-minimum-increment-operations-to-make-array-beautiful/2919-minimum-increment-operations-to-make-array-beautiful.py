class Solution:
    def minIncrementOperations(self, nums: List[int], k: int) -> int:
        if len(nums)==3:
            if max(nums)>=k:
                return 0
            else:
                return k-max(nums)
        @cache
        def solve(index):
            if index+3>len(nums):
                return 0
            ans=float('inf')
            for i in range(index,min(len(nums),index+3)):
                if nums[i]<k:
                    ans=min(ans,k-nums[i]+solve(i+1))
                else:
                    ans=min(ans,solve(i+1))
            return ans
        x=solve(0)
        if x>=float('inf'):return 0
        return x
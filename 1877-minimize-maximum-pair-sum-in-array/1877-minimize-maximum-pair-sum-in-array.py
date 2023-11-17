class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums.sort()
        left = 0
        right = len(nums)-1
        ans = -float('inf')
        while left<right:
            ans = max(ans,nums[left]+nums[right])
            left+=1
            right-=1
        return ans
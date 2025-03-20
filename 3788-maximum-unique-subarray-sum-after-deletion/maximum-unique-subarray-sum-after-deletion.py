class Solution:
    def maxSum(self, nums: List[int]) -> int:
        if max(nums)<0:
            return max(nums)
        elif len(nums)==1:
            return nums[0]
        else:
            s=set()
            for i in range(len(nums)):
                if nums[i]>0:
                    s.add(nums[i])
            return sum(s)
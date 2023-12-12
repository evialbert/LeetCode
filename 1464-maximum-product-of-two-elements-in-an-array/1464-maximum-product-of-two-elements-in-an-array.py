class Solution(object):
    def maxProduct(self, nums):
        
        nums = sorted(nums)

        return (nums[-1] - 1) * ( nums[-2] - 1)
        
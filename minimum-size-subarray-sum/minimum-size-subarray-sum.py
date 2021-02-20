class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        i, j, pres, res = 0 , 0 , 0, len(nums) + 1

        while j < len(nums):
            pres += nums[j]; j += 1
            while pres >= s:
                res = min(res, j - i)
                pres -= nums[i]; i+= 1
        return res if res != len(nums) + 1 else 0
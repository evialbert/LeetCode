class Solution(object):

    def maxProduct(self, nums):

        """

        :type nums: List[int]

        :rtype: int

        """

        mx = nums[0]

        mn = nums[0]

        ret = nums[0]

        for n in nums[1:]:

            if n < 0: 

                mx, mn = mn, mx

            mn = min(n, mn * n)

            mx = max(n, mx * n)

            ret = max(mx, ret)

        return ret
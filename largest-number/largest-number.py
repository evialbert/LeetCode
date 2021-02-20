class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        def numOrder(x, y):
            left = int(x + y)
            right = int(y + x)
            return left - right

        if len(nums) == 0:
            return ""
        numsStr = [str(n) for n in nums]
        numsStr.sort(reverse=True, cmp=numOrder)
        if numsStr[0] == '0':
            return "0"
        else:
            return "".join(numsStr)
class Solution(object):

    def permuteUnique(self, nums):

        """

        :type nums: List[int]

        :rtype: List[List[int]]

        """



        res = []

        self.getPer(nums, res, 0)

        return res



    def getPer(self, nums, res, begin):

        if begin == len(nums):

            res.append(list(nums))

        visit = set()

        for i in range(begin, len(nums)):

            if nums[i] in visit:

                continue

            visit.add(nums[i])

            nums[begin], nums[i] = nums[i], nums[begin]

            self.getPer(nums, res, begin+1)

            nums[begin], nums[i] = nums[i], nums[begin]


class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        s = set()
        maximum = -1

        for i in range(len(nums)):
            if (-1*nums[i]) not in s:
                s.add(nums[i])
            else:
                if abs(nums[i]) > maximum:
                    maximum = abs(nums[i])
        return maximum

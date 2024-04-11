class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        firstmax = max(nums)
        if len(nums)<3:
            return firstmax
        else:
            secondmax = -9999999999999999999999
            for a in nums:
                if secondmax < a and a != firstmax:
                    secondmax = a
            nums = sorted(nums, reverse=True)
            for a in range(2, len(nums)):
                if nums[a] != firstmax and nums[a]!= secondmax:
                    thirdmax = nums[a]
                    return thirdmax
            return firstmax
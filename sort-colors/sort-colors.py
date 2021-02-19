class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """ Do not return anything, modify nums in-place instead. """
        p0, p1, p2 = 0, 0, len(nums) - 1
        while p1 <= p2:
            if nums[p1] == 0:
                nums[p0], nums[p1] = nums[p1], nums[p0]
                p0 += 1
                p1 += 1
            elif nums[p1] == 2:
                nums[p1], nums[p2] = nums[p2], nums[p1]
                p2 -= 1
            else:
                p1 += 1
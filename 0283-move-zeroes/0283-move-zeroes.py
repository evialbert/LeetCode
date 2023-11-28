class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        j = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                continue
            if nums[i] != 0:
                a = nums[j]
                nums[j] = nums[i]
                nums[i] = a
                j = j+1
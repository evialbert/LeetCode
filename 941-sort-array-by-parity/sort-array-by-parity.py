class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        left=0
        right=len(nums)-1
        n = len(nums)
        while left<right:
            while left < right and nums[left] % 2 == 0:
                left += 1
            while left < right and nums[right] % 2 != 0:
                right -= 1
            if left < right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1    
        return nums
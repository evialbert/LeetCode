class Solution:
    def sumOfGoodNumbers(self, nums: List[int], k: int) -> int:
        result = 0
        for i, elem in enumerate(nums):
            if (
                (i - k >= 0 and elem <= nums[i - k])
                or (i + k < len(nums) and elem <= nums[i + k])
            ):
                continue
            result += elem
        return result
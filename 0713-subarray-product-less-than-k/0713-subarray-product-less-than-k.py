class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k <= 1:
            return 0

        i, j = 0, 0
        product, count = 1, 0

        while j < len(nums):
            product *= nums[j]

            while product >= k:
                product //= nums[i]
                i += 1

            count += j - i + 1
            j += 1

        return count
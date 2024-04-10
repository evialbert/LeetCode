class Solution:
    def minOperationsToMakeMedianK(self, nums: List[int], k: int) -> int:

        if len(nums) == 1:
            return abs(k - nums[0])

        nums.sort()

        mid = len(nums) // 2

        if nums[mid] == k:
            return 0
        elif nums[mid] > k:
            counter = 0
            i = mid
            while nums[i] > k and i >= 0:
                counter += abs(k - nums[i])
                i -= 1
            return counter
        else:
            counter = 0
            i = mid
            while i < len(nums) and nums[i] < k:
                counter += k - nums[i]
                i += 1
            return counter
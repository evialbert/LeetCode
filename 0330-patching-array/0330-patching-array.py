class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        sum, patch, i = 0, 0, 0

        while sum < n:
            if i < len(nums) and nums[i] <= sum+1:
                sum += nums[i]
                i += 1
            else:
                patch += 1
                sum += sum+1

        return patch
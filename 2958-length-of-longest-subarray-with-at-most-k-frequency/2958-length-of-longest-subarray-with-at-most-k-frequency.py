class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        if len(nums) == 1:
            return 1
        if len(nums) == 2:
            if nums[0] != nums[1]:
                return 2
            else:
                return 1
        dp = {}
        left = 0
        right = 0
        result = 0
        def cut(num: int):
            dp[num] -= 1
        while right < len(nums):
            if nums[right] in dp:
                dp[nums[right]] += 1
                while dp[nums[right]] > k:
                    cut(nums[left])
                    left += 1
                result = max(result, right - left + 1)
            else:
                dp[nums[right]] = 1
                result = max(result, right - left + 1)
            right += 1
        return result
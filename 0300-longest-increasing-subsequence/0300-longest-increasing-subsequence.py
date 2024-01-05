class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        # base
        dp = [0] * n
        res = 0
        # recursive
        for i in range(n):
            left, right = 0, res
            while left < right:
                # use dichotomy to find the first dp[j] > nums[i]
                mid = (left + right) // 2
                if dp[mid] < nums[i]:
                    left = mid + 1
                else:
                    right = mid
            # if there exist dp[j] > nums[i], then 
            # dp[left] is the first dp[j]
            # if there doesn't exist dp[j] > nums[i], then
            # left = right = res
            dp[left] = nums[i]
            if left == res:
                res += 1
        # result
        return res
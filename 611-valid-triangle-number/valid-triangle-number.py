class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        res = 0

        for i in range(n-2):
            for j in range(i+1, n-1):
                k = bisect_left(nums, nums[i]+nums[j])
                res += max(0, k - j - 1)

        return res
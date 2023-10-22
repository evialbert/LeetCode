class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        n = len(nums)
        left = [-1] * n
        right = [-1] * n
        leftMin = nums[0]
        rightMin = nums[-1]
        res = float("inf")
        for i in range(1, n):
            if nums[i] > leftMin:
                left[i] = leftMin
            else:
                leftMin = nums[i]
        for i in range(n - 2, -1, -1):
            if nums[i] > rightMin:
                right[i] = rightMin
            else:
                rightMin = nums[i]
            if left[i] != -1 and right[i] != -1:
                res = min(res, nums[i] + left[i] + right[i])
        return res if res != float("inf") else -1

class Solution:
    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        nums=[float("-inf")]+nums+[float("inf")]
        n = len(nums)
        lc = 1
        rc = 1

        for i in range(1, n):
            if nums[i] <= nums[i - 1]:
                break
            lc += 1

        for i in range(n - 2, -1, -1):
            if nums[i] >= nums[i + 1]:
                break
            rc += 1

        ans=0
        for i in range(lc):
            j = bisect.bisect_left(nums, nums[i]+1, lo=max(i + 2, n - rc))
            if j < n and nums[j] > nums[i]:
                ans += n - j

        return ans
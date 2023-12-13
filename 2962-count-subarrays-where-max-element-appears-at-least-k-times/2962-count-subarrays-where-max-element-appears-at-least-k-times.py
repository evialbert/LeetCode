class Solution:
    def countSubarrays(self, nums, k):
        n = len(nums)
        m = max(nums)
        i, j, count, ans = 0, 0, 0, 0

        while j < n:
            if nums[j] == m:
                count += 1
            if count >= k:
                while count >= k:
                    ans += n - j
                    if nums[i] == m:
                        count -= 1
                    i += 1
            j += 1
        return ans
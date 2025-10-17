class Solution:
    def bowlSubarrays(self, nums: List[int]) -> int:    
        n = len(nums)
        l, r = 1, n - 2
        left_max, right_max = nums[0], nums[n - 1]
        res = 0
        while l <= r:
            if left_max < right_max:
                if nums[l] < left_max:
                    res += 1
                left_max = max(left_max, nums[l])
                l += 1
            else:
                if nums[r] < right_max:
                    res += 1
                right_max = max(right_max, nums[r])
                r -= 1
        return res
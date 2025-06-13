class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:

        nums.sort()
        n = len(nums)
        l = 0
        r = nums[-1] - nums[0]
        res = 0

        def helper(mid):
            count = 0
            i = 1
            while i < n:
                if nums[i] - nums[i - 1] <= mid:
                    count += 1
                    i += 2
                else:
                    i += 1
            return count

        while r >= l:
            mid = (r + l) // 2
            count = helper(mid)
            if count >= p:
                res = mid
                r = mid - 1
            else:
                l = mid + 1

        return res
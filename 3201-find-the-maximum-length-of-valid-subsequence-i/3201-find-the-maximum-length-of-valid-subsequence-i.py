class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        def helper(first, second):
            if len(nums) <= 2:
                return len(nums)
            search = first
            res = 0
            for i in range(len(nums)):
                if nums[i] % 2 == search:
                    res += 1
                    search = first if search == second else second
            return res

        return max(helper(0, 0), helper(0, 1), helper(1, 0), helper(1, 1))
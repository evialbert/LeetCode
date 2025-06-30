class Solution:
    def checkEqualPartitions(self, nums: List[int], target: int) -> bool:
        def backtrack(i, prod1, prod2):
            if i == len(nums) and prod1 == prod2 == target:
                return True

            if i == len(nums) or prod1 > target or prod2 > target:
                return False

            if nums[i] == 1:
                return backtrack(i + 1, prod1, prod2)

            return backtrack(i + 1, prod1 * nums[i], prod2) or backtrack(i + 1, prod1, prod2 * nums[i])

        return backtrack(0, 1, 1)

            
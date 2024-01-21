class Solution:
    def canSortArray(self, nums: List[int]) -> bool:
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                if bin(nums[i]).count('1') != bin(nums[j]).count('1') and nums[i] > nums[j]:
                    return False
        return True
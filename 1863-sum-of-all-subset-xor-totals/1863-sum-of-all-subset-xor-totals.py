class Solution:
    def subsetXORSum(self, nums: List[int]) -> int:
        n=len(nums)
        all_or=0
        for i in range(n):
            all_or|=nums[i]
        return all_or*(1<<(n-1))
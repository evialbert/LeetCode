class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        curSum = 0

        for i in range(len(nums)):
            for j in range(i,len(nums) + 1):
                curSum += len(set(nums[i:j])) ** 2
        return curSum
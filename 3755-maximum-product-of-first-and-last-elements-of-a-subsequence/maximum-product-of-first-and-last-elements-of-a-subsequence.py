class Solution:
    def maximumProduct(self, nums: List[int], m: int) -> int:

        minis = [float("inf")] * len(nums)
        minis[-1] = nums[-1]
        maxis = [float("-inf")] * len(nums)
        maxis[-1] = nums[-1]
        for i in range(len(nums)-2, -1, -1):
            maxis[i] = max(maxis[i+1], nums[i])
            minis[i] = min(minis[i+1], nums[i])

        finalAnswer = float("-inf")
        for i in range(len(nums)):
            if (i + m - 1) < len(nums):
                finalAnswer = max(finalAnswer, nums[i]*maxis[i+m-1], nums[i]*minis[i+m-1])
        return finalAnswer
                
                
            
            
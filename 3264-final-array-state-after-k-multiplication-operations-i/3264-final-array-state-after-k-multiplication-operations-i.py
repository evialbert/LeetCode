class Solution:
    def getFinalState(self, nums: List[int], k: int, multiplier: int) -> List[int]:
        for _ in range(k):
            mini=min(nums)
            for i,num in enumerate(nums):
                if(num==mini):
                    nums[i]=num*multiplier
                    break
        return nums
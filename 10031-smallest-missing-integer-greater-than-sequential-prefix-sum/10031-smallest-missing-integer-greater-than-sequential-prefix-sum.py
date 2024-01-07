class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        
        ans = nums[0]

        for i, (n1, n2) in enumerate(pairwise(nums)):

            if n2 - n1 == 1:  ans+= n2
            else: break
        
        while ans in nums:  ans+= 1

        return ans
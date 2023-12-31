class Solution:
    def hasTrailingZeros(self, nums: List[int]) -> bool:
        ans = 0
        for num in nums:
            if num%2==0:
                ans+=1
                if ans>1:
                    return True
        return False
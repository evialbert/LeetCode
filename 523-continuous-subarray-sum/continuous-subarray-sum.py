class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        rems = {0:-1}
        for i,x in enumerate(accumulate(nums)):
            if i - rems.setdefault(x%k, i) >= 2: return True
        return False
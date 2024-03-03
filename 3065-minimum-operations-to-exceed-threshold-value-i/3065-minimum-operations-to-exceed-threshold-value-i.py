class Solution:
    """
    def minOperations(self, nums: List[int], k: int) -> int:
        result = 0
        for i in nums:
            result += 1 if i < k else 0
        return result 
    """
    def minOperations(self, nums: List[int], k: int) -> int:
        result = 0
        while min(nums) < k:
            result += 1
            nums.remove(min(nums))
        return result     
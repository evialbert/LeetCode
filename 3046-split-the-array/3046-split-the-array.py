class Solution:
    def isPossibleToSplit(self, nums: List[int]) -> bool:
        count = Counter(nums)
        
        for val in count.values():
            if val>2:
                return False
        return True
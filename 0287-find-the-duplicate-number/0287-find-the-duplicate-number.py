class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        return [i for i,j in Counter(nums).items() if j>=2][0]
class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        S, N = sum(nums), len(nums)
        return [(S:=S-2*n) - (N:=N-2)*n for n in nums]

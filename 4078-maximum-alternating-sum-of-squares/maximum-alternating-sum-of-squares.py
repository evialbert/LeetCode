class Solution:
    def maxAlternatingSum(self, nums: list[int]) -> int:
        arr = [x**2 for x in nums]
        arr.sort(reverse=True)
        k = (len(arr)+1)//2
        return sum(arr[:k]) - sum(arr[k:])
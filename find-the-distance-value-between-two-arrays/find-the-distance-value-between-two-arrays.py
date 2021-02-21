class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        return sum([sum([abs(i-j)>d for i in arr2])==len(arr2) for j in arr1])
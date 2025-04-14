class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        return sum(abs(x-y)<=a and abs(y-z)<=b and abs(x-z)<=c for x,y,z in combinations(arr,3))
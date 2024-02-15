class Solution:
    def canMeasureWater(self, j1: int, j2: int, target: int) -> bool:
        return target == 0 or j1 + j2 >= target and target % gcd(j1, j2) == 0
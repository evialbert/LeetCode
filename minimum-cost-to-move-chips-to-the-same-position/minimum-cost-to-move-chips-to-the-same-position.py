class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        return min(len(list(filter(lambda x: x % 2 == 0, chips))), len(chips)-len(list(filter(lambda x: x % 2 == 0, chips))))
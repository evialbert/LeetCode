class Solution:
    def minTimeToVisitAllPoints(self, x: List[List[int]]) -> int:
        return sum([max(abs(x[i-1][0] - x[i][0]), abs(x[i-1][1] - x[i][1])) for i in range(1, len(x))])
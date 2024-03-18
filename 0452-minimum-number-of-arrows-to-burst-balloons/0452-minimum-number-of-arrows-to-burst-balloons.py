class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points = sorted(points, key = lambda x:x[1])
        end = None
        count = 0
        for p in points:
            if end is None or end < p[0]:
                end = p[1]
                count += 1
        return count
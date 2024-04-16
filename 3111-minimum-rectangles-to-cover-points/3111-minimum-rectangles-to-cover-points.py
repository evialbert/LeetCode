class Solution:
    def minRectanglesToCoverPoints(self, points: List[List[int]], w: int) -> int:
        points.sort()
        res=1
        x=points[0][0]
        for i in range(len(points)):
            if abs(x-points[i][0])>w:
                x=points[i][0]
                res+=1
        return res
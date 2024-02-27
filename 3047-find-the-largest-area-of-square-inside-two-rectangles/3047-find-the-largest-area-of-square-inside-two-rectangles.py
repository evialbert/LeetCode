class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        n = len(bottomLeft)

        answer = 0
        for i in range(n):
            for j in range(i + 1, n):
                lx = max(bottomLeft[i][0], bottomLeft[j][0])
                ly = max(bottomLeft[i][1], bottomLeft[j][1])
                rx = min(topRight[i][0], topRight[j][0])
                ry = min(topRight[i][1], topRight[j][1])
                
                if rx - lx > 0 and ry - ly > 0:
                    answer = max(answer, min(rx - lx, ry - ly) ** 2)
        return answer
class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        x = y = 0
        dx, dy = 0, 1
        for ss in instructions: 
            if ss == "G": x, y = x+dx, y+dy
            elif ss == "L": dx, dy = -dy, dx
            else: dx, dy = dy, -dx
        return (x, y) == (0, 0) or (dx, dy) != (0, 1)
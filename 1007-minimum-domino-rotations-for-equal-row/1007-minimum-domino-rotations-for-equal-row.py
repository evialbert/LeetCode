class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        n = len(tops)

        def check( curr ):
            turnsUp, turnsDown = 0, 0
            for i in range(n):
                if tops[i] != curr and bottoms[i] != curr:
                    return -1 
                elif tops[i] != curr:
                    turnsUp += 1 
                elif bottoms[i] != curr:
                    turnsDown += 1 
            return min(turnsUp, turnsDown)

        ret = check(tops[0])
        if ret != -1 or tops[0] == bottoms[0]:
            return ret 
        return check(bottoms[0])
class Solution:
    def numberOfWays(self, corridor: str) -> int:
        if not corridor:
            return 0

        seatCount = 0
        res = 1
        numPositions = 0

        for obj in corridor:
            if obj == 'S':
                if seatCount < 2:
                    seatCount += 1
                else:
                    seatCount = 1
                    res =  (res * numPositions) % (10**9 + 7)
                    numPositions = 0
            
            if seatCount == 2:
                numPositions += 1

        if seatCount < 2:
            return 0

        return res
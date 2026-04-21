class Solution:
    def minimumIndex(self, capacity: list[int], itemSize: int) -> int:
        minbox = sys.maxsize
        idx = -1
        for i in range(len(capacity)):
            cap = capacity[i]
            if cap >= itemSize:
                if minbox > cap:
                    minbox = cap
                    idx = i
        
        return idx
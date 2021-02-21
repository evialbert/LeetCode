class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        r = [0 for _ in range(n)]
        c = [0 for _ in range(m)]
        
        for ri, ci in indices:
            r[ri] += 1
            c[ci] += 1
        
        res = 0
        for i in range(n):
            tres = []
            for j in range(m):
                if (r[i] + c[j]) % 2 == 1:
                    res += 1
                
        
        return res
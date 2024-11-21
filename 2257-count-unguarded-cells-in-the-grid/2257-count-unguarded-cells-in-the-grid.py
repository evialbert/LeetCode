class Solution:
    def countUnguarded(self, m: int, n: int, guards: List[List[int]], walls: List[List[int]]) -> int:
        dirs = [(-1,0), (1,0), (0,-1), (0,1)]
        guarded = set()
        guardset = set(tuple(g) for g in guards)
        wallset = set(tuple(w) for w in walls)
        for gx, gy in guards:
            for dx, dy in dirs:
                x = gx
                y = gy
                while (0 <= dx + x < m) and (0 <= dy + y < n) and (tuple([x+dx, y+dy]) not in wallset) and (tuple([x+dx, y+dy]) not in guardset):
                    guarded.add(tuple([x+dx, y+dy]))
                    x += dx
                    y += dy
        
        return m*n - len(guardset) - len(wallset) - len(guarded)
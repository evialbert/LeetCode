class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        q=[(1,0,0)]
        if grid[0][0]:return -1
        visited=set((0,0))
        rows,cols=len(grid),len(grid[0])
        if grid[-1][-1]:return -1
        directions=((0,1),(1,0),(0,-1),(-1,0),(1,1),(-1,-1),(1,-1),(-1,1))
        while q:
            val,r,c=q.pop(0)
            if r==rows-1 and c==cols-1 :return val
            for i,j in directions:
                rr,cc=r+i,c+j
                if 0<=rr<rows and 0<=cc<cols and not grid[rr][cc] and (rr,cc) not in visited:
                    visited.add((rr,cc))
                    q.append((val+1,rr,cc))
        return -1

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        ROWS = len(grid)
        COLS = len(grid[0])
        ref = [[float("inf") for i in range(COLS)] for j in range(ROWS)]
        hq = [[(grid[ROWS-1][COLS-1]),ROWS-1,COLS-1]]
        iter = [[-1,0],[1,0],[0,-1],[0,1]]
        while hq:
            curr_big,idx_x,idx_y = heapq.heappop(hq)
            if ref[idx_x][idx_y]>curr_big:
                ref[idx_x][idx_y] = curr_big
                for x1,y1 in iter:
                    x,y = idx_x+x1,idx_y+y1
                    if x>=0 and x<ROWS and y>=0 and y<COLS:
                        if (x,y)==(0,0):
                            print(f'reached')
                            return max(curr_big,grid[x][y])
                        
                        if ref[x][y]>curr_big:
                            heapq.heappush(hq,[max(curr_big,grid[x][y]),x,y])
        return ref[0][0] 
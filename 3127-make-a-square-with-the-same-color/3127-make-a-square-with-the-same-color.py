class Solution:
    def canMakeSquare(self, grid: List[List[str]]) -> bool:
        m,n= len(grid),len(grid[0])
        direction = [[0,0],[1,0],[0,1],[1,1]]
        for i in range(m-1):
            for j in range(n-1):
                black,white=0,0
                for dx,dy in direction:
                    x,y=i+dx,j+dy
                    if grid[x][y]=='B':
                        black+=1
                    else:
                        white+=1
                if black>=3 or white>=3:
                    return True
        return False
                    
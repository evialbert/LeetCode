class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n_island, n_row, n_col= 0, len(grid), len(grid[0])
        ## caution: do not use "[[0]*n_col]*5"
        visited = [[0]*n_col for _ in range(n_row)] * n_row
        for i in range(n_row):
            for j in range(n_col):
                if grid[i][j]=='1' and visited[i][j]==0:
                    visited[i][j] = 1
                    n_island += 1
                    l = [(i,j)]
                    while l:
                        ii, jj = l.pop(0)
                        up, right, down, left = (ii-1,jj), (ii,jj+1), (ii+1,jj), (ii,jj-1)
                        directions = []
                        if up[0]>=0: directions.append(up)
                        if right[1]<n_col: directions.append(right)
                        if down[0]<n_row: directions.append(down)
                        if left[1]>=0: directions.append(left)
                        for d in directions:
                            if grid[d[0]][d[1]]=='1' and visited[d[0]][d[1]]==0:
                                visited[d[0]][d[1]] = 1
                                l.append(d)
        return n_island  
class Solution:
    def minCost(self, grid: list[list[int]]) -> int:
        G=grid;R=len(G);C=len(G[0])
        MEMO=[[[-1]*2**10 for _ in range(C)] for _ in range(R)]
        res=inf
        def dfs(i,j,xr):
            nonlocal res
            if i==R or j==C: return False
            xr^=G[i][j]
            if i==R-1 and j==C-1:
                res=min(res,xr)
                MEMO[i][j][xr]=True
                return
            if MEMO[i][j][xr]!=-1: return MEMO[i][j][xr]
            bot=dfs(i+1,j,xr);right=dfs(i,j+1,xr)
            MEMO[i][j][xr]=bot or right
            return res
        dfs(0,0,0)
        return res
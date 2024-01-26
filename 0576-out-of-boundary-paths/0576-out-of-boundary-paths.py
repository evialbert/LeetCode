class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
     
        @cache
        def dp(i,j, k):
            if k<min(i+1, m-i, j+1, n-j):
                return 0
            ways = 0
            for di, dj in ((1,0),(-1,0),(0,1),(0,-1)):
                ni,nj = i+di, j+dj
                ways+=dp(ni,nj,k-1)  if  (0<=ni<m) and (0<=nj<n) else 1       
            return ways
        return dp(startRow, startColumn, maxMove)%(1000000007)
                    
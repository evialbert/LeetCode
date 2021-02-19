class Solution:
    def uniquePathsWithObstacles(self, arr: List[List[int]]) -> int:
        m = len(arr)
        if not m:return 0
        n = len(arr[0])
        if not n:return 0
        if arr[0][0] == 1:return 0
        def dfs(arr,i,j):
            if arr[i][j]!=0 and arr[i][j]!='*':return arr[i][j]
            if arr[i][j] == '*':return 0
            down,right = 0,0
            if i<m-1:down = dfs(arr,i+1,j)
            if j<n-1:right = dfs(arr,i,j+1)
            arr[i][j] = down+right
            return arr[i][j]

        for i in range(m):
            for j in range(n):
                if arr[i][j] == 1:arr[i][j] = '*'
        arr[-1][-1] = 1 if arr[-1][-1] == 0 else 0
        dfs(arr,0,0)
        return arr[0][0]
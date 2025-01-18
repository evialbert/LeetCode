class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        print(m,n)

        color = [[-1]*n for x in range(m)]

        q = deque()
        q.append((0,0))
        cost = 0

        while len(q):
            l = len(q)
            for _ in range(l):
                (i,j) = q.popleft()
                while i<m and j<n and i>=0 and j>=0:
                    if color[i][j] >= 0:
                        break
                    if i==m-1 and j==n-1:
                        return cost
                    color[i][j] = cost
                    if j>0:
                        q.append((i, j-1))
                    if j<n-1:
                        q.append((i, j+1))
                    if i>0:
                        q.append((i-1, j))
                    if i<m-1:
                        q.append((i+1, j))
                    if grid[i][j]==1:
                        j += 1
                    elif grid[i][j]==2:
                        j -= 1
                    elif grid[i][j]==3:
                        i += 1
                    else:
                        i -= 1
            cost += 1
        print("err")
        return cost
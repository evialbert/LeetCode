class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        m, n = len(land), len(land[0])
        ans = []
        for i in range(m):
            for j in range(n):
                if land[i][j] < 1: continue
                q = collections.deque([[i, j]])
                while q:
                    x, y = q.popleft()
                    if land[x][y] == -1: continue
                    land[x][y] = -1
                    for dx, dy in [[0, 1], [1, 0]]:
                        xx, yy = x + dx, y + dy
                        if xx < m and yy < n and land[xx][yy] == 1:
                            q.append([xx, yy])
                ans.append([i, j, x, y])
        return ans
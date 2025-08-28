class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        d = defaultdict(list)

        for i in range(m):
            for j in range(n):
                d[j - i].append(grid[i][j])

        for key in d:
            if key > 0:
                d[key] = sorted(d[key], reverse=True)
            else:
                d[key] = sorted(d[key])
        
        for i in range(m):
            for j in range(n):
                grid[i][j] = d[j - i].pop()

        return grid
class Solution:
    def minimumObstacles(self, grid: List[List[int]]) -> int:
        heap = [(0, 0, 0)] # cost, x, y
        m, n = len(grid), len(grid[0])
        directions = [[1, 0], [0, 1], [-1, 0], [0, -1]]
        visit = set([(0, 0)])
        while heap:
            cost, x, y = heapq.heappop(heap)
            if x == m - 1 and y == n - 1:
                return cost
            for d in directions:
                dx, dy = d[0] + x, d[1] + y
                if 0 <= dx < m and 0 <= dy < n and (dx, dy) not in visit:
                    visit.add((dx, dy))
                    if grid[dx][dy] == 1:
                        heapq.heappush(heap, (cost + 1, dx, dy))
                    else:
                        heapq.heappush(heap, (cost, dx, dy))
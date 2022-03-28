class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        graph = defaultdict(list)
        ROW_SIZE = len(heights)
        COL_SIZE = len(heights[0])
        
        for col in range(COL_SIZE):
            for row in range(ROW_SIZE):
                directions = [(-1, 0), (1,0), (0,1), (0,-1)]
                for x,y in directions:
                    if 0 <= row + x < ROW_SIZE and 0 <= col + y < COL_SIZE:
                        dist = abs(heights[row+x][col+y] - heights[row][col])
                        graph[(row, col)].append((dist, (row+x, col+y)))
        
        pq = [(0, 0, 0)]
        minEffort = [[float('inf') for _ in range(COL_SIZE)] for _ in range(ROW_SIZE)]
        visited = set()

        while pq:
            currEffort, pointX, pointY = heappop(pq) 
            for nei in graph[(pointX, pointY)]:
                nextEffort, (nextX, nextY) = nei
                newEffort = max(currEffort, nextEffort)
                if not (nextX, nextY) in visited and newEffort < minEffort[nextX][nextY]:
                    minEffort[nextX][nextY] = newEffort
                    heappush(pq, (newEffort, nextX, nextY))
            visited.add((pointX, pointY))
            
        return minEffort[-1][-1] if minEffort[-1][-1] != float('inf') else 0
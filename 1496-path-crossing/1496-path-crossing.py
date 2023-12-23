class Solution:
    def isPathCrossing(self, path: str) -> bool:
        i, j = 0, 0
        
        visited = {(i, j)}
        for d in path:
            if d == "N":
                i -= 1
            elif d == "E":
                j += 1
            elif d == "S":
                i += 1
            else:
                j -= 1
            
            if (i, j) in visited:
                return True
            
            visited.add((i, j))
        
        return False
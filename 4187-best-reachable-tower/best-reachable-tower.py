class Solution:
    def bestTower(self, towers: List[List[int]], center: List[int], radius: int) -> List[int]:

        result = [-1, -1]
        max_val = -1

        for x, y, q in towers:

            if abs(x - center[0]) + abs(y - center[1]) <= radius:
                if q > max_val:
                    max_val = q
                    result = [x, y]
                if q == max_val and x < result[0]:
                    result = [x, y]
                if q == max_val and x == result[0] and y < result[1]:
                    result = [x, y]
                
        return result
            
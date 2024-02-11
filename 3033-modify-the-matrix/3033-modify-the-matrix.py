class Solution:
    def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        n, m = len(matrix), len(matrix[0])
        res = [[] for _ in range(n)]
        max_for_m = {}
        
        for i in range(n):
            for j in range(m):
                res[i].append(matrix[i][j])
                max_for_m[j] = max(max_for_m.get(j, -1), matrix[i][j])
                
        for i in range(n):
            for j in range(m):
                if res[i][j]  == -1:
                    res[i][j] = max_for_m[j] 
                    
        return res
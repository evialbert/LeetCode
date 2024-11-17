class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        
        map = defaultdict(list)
        eqns = {}

        for i,j in equations:
           map[i].append(j)
           map[j].append(i)

        for i in range(len(equations)):
            eqns[(equations[i][0], equations[i][1])] = values[i]
        
        
        def connected( node, target, ans):
            if node in visited:
                return False
            visited.add(node)
            if target in map[node]:
                if (node, target) in eqns:
                    val = ans * eqns[(node, target)]
                else:
                    val = ans / eqns[(target, node)]
                res.append(val)
                return True
            
            for nei in map[node]:
                if (node, nei) in eqns:
                    val = ans * eqns[(node, nei)]
                else:
                    val = ans / eqns[(nei, node)]
                if connected(nei, target, val):
                    return True
        res = []
        for i,j in queries:
            visited = set()
            if not connected(i, j, 1):
                res.append(-1.0)

        return res
            
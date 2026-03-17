class Solution:
    def minimumFlips(self, n: int, edges: List[List[int]], start: str, target: str) -> List[int]:
        graph = [[] for x in range(n)]
        d = {}
        index=0
        for x in edges:
            graph[x[0]].append(x[1])
            graph[x[1]].append(x[0])
            d[(x[0], x[1])] = index
            index = index + 1

        v = [0 for x in range(n)]
        s = [int(start[x]) for x in range(n)]
        t = [int(target[x]) for x in range(n)]
        i = [0 for x in range(n)]
        p = [x for x in range(n)]
        ans = self.dfs(0, v, i, t, graph, 0, p, s)

        if ans !=0:
            return [-1]
        ans = []
        for x in range(n):
            if i[x]!= 0:
                ans.append([x,p[x]])
        result = []
        for x in ans:
            if (x[0],x[1]) in d:
                result.append(d[(x[0] , x[1])])
            else:
                result.append(d[(x[1] , x[0])])
        result.sort()
        return result


    def dfs(self, node, v, i, t, graph, p1, p, s):
        p[node] = p1
        v[node] = 1
        ans = 0
        for x in graph[node]:
            if v[x] == 0:
                ans = ans + self.dfs(x, v, i, t, graph, node,p, s)
        if t[node] == s[node]:
            i[node] = ans % 2
            return i[node]
        else:
            if ans% 2== 1:
                i[node] = 0
                return 0
            else:
                i[node] = 1
                return 1

        
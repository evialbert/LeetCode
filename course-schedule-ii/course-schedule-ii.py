class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        indegree = [0] * numCourses
        edge = defaultdict(list)
        for x, y in prerequisites:
            indegree[x] += 1
            edge[y].append(x)
        q = [i for i in range(numCourses) if indegree[i] == 0]
        res = []
        while q:
            cur = q.pop()
            res.append(cur)
            for n in edge[cur]:
                indegree[n] -= 1
                if indegree[n] == 0:
                    q.append(n)
        return res if len(res) == numCourses else []
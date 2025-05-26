class Solution:
    def largestPathValue(self, colors: str, edges: List[List[int]]) -> int:
        queue = deque()
        dic = {}
        n = len(colors)
        indegree = [0] * n
        count = [{} for _ in range(n)]
        max_count = 0

        for x, y in edges:
            if y in dic:
                dic[y].append(x)
            else:
                dic[y] = [x]
            indegree[x] += 1
        
        for i in range(n):
            if indegree[i] == 0:
                queue.append(i)

        while queue:
            cur = queue.popleft()
            
            color = colors[cur]
            if color in count[cur]:
                count[cur][color] += 1
            else:
                count[cur][color] = 1
            max_count = max(max_count, count[cur][color])
            if cur in dic:
                for neighbor in dic[cur]:
                    for key, val in count[cur].items():
                        if key in count[neighbor]:
                            count[neighbor][key] = max(val, count[neighbor][key])
                        else:
                            count[neighbor][key] = val
                    indegree[neighbor] -= 1
                    if indegree[neighbor] == 0:
                        queue.append(neighbor)
        
        for i in indegree:
            if i != 0:
                return -1
        return max_count
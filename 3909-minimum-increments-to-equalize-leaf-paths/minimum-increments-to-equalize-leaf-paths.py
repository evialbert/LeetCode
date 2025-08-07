class Solution:
    def minIncrease(self, n: int, edges: List[List[int]], cost: List[int]) -> int:
        def dfs(node, parent = None):
            nonlocal need_changes
            max_cost = cost[node]
            max_count = 0
            children = 0
            for nei in adj_list[node]:
                if nei != parent:
                    children += 1
                    cur_cost = cost[node] + dfs(nei, node)
                    if cur_cost > max_cost:
                        max_cost = cur_cost
                        max_count = 1
                    elif cur_cost == max_cost:
                        max_count += 1
                    max_cost = max(max_cost, cur_cost)
            need_changes += children - max_count
            return max_cost
            
        adj_list = defaultdict(list)
        for u,v in edges:
            adj_list[u].append(v)
            adj_list[v].append(u)
        need_changes = 0
        dfs(0)
        return need_changes
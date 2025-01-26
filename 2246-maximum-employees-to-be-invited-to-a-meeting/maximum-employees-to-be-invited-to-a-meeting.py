class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        size = len(favorite)
        edges = defaultdict(list)
        for i,v in enumerate(favorite):
            edges[v].append(i)
        
        def dfs_depend(node: int, father: int)->int:
            res = 1
            for i in edges[node]:
                if i != father:
                    res = max(res, 1 + dfs_depend(i, node))
            return res

        circle_res = 0
        circle_set = set()
        def dfs_circle(node: int, father: int, root: int, cur: int):
            nonlocal circle_res,circle_set
            circle_set.add(node)
            if node == favorite[root]:
                circle_res = max(circle_res, cur)
                return 
            for i in edges[node]:
                if i != father and i not in circle_set:
                    dfs_circle(i, node, root, cur + 1)

        depend_visited = set()
        depend_res = 0
        for i in range(size):
            if favorite[favorite[i]] == i:
                if i not in depend_visited and favorite[i] not in depend_visited:
                    depend_visited.add(i)
                    depend_visited.add(favorite[i])
                    depend_res +=dfs_depend(i, favorite[i]) + dfs_depend(favorite[i],i)
            else:
                if i not in circle_set:
                    dfs_circle(i, -1, i , 1)
        return max(depend_res, circle_res)
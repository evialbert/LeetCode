class Solution:
    def kthSmallest(self, par: List[int], vals: List[int], queries: List[List[int]]) -> List[int]:
        n = len(par)
        childs = {i:set([]) for i in range(n)}
        for i,p in enumerate(par):
            if p!=-1:
                childs[p].add(i)
        xor = [0]*n
        self.nowor = 0
        def dfs(node):
            self.nowor = self.nowor^vals[node]
            xor[node] = self.nowor
            for child in childs[node]:
                dfs(child)
            self.nowor = self.nowor^vals[node]
        ansdic = {}
        for i,(u,k) in enumerate(queries):
            if u not in ansdic:
                ansdic[u] = {}
            if k not in ansdic[u]:
                ansdic[u][k] = []
            ansdic[u][k].append(i)
        self.res = [-1]*len(queries)
        dfs(0)
        def dfs2(node):
            res = SortedSet([xor[node]])
            for child in childs[node]:
                newset = dfs2(child)
                if len(newset) > len(res):
                    res,newset = newset,res
                res.update(newset)
            if node in ansdic:
                for k in ansdic[node]:
                    if k <= len(res): 
                        ans = res[k-1]
                        for i in ansdic[node][k]:
                            self.res[i] = ans
            return res
        dfs2(0)
        return self.res
            

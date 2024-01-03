class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        g=defaultdict(list)
        for old,new,cos in zip(original,changed,cost):
            g[old].append([new,cos])
        
        @cache
        def dfs(node1,node2):
            pq=[(0,node1)]
            degree={}
            while pq:
                cos,node=heappop(pq)
                if node==node2: return cos
                for nxt,co in g[node]:
                    if nxt not in degree or degree[nxt]>cos+co:
                        heappush(pq,(cos+co,nxt))
                        degree[nxt]=cos+co
            return inf
        
        poss_lengths=sorted(list(set(len(o) for o in original)))

        dp=[0]+[inf]*len(target)

        for i in range(len(target)):
            if dp[i]==inf:
                continue

            if target[i]==source[i]:
                dp[i + 1]=min(dp[i + 1], dp[i])

            for l in poss_lengths:
                if i+l>=len(dp): break               
                sub_source=source[i:i+l]
                sub_target=target[i:i+l]
                if sub_source in g and dfs(sub_source,sub_target)<inf:
                    dp[i+l]=min(dp[i+l], dp[i]+dfs(sub_source,sub_target))

        return dp[-1] if dp[-1]!=inf else -1
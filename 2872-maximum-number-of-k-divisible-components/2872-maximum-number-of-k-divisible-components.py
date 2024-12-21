class Solution:
    
    def dfs(self,i,p,vis,graph,val,k):
        if(vis[i]):return 0,0
        vis[i]=1
        s=val[i]%k
        ans=0
        for node in graph[i]:
            if(node==p):continue
            a,b=self.dfs(node,i,vis,graph,val,k)
            s=(s+b)%k
            ans+=a
        if(s==0):ans+=1
        return ans,s
        
    
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        graph=[[] for i in range(n)]
        for e in edges:
            graph[e[0]].append(e[1])
            graph[e[1]].append(e[0])
        vis=[0 for i in range(n)]
        a,b=self.dfs(0,-1,vis,graph,values,k)
        return max(a,1)
        
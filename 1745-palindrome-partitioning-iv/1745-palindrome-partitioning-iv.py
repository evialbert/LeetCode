class Solution:
    def checkPartitioning(self, s: str) -> bool:
        n = len(s)
        if n == 1:
            return [[s]]
        
        self.graph = defaultdict(list)
        
        for i in range( 2*n - 1):
            self.expand_around(s, i)
            
        def dfs(i=0, rem=3):
            if rem == 1:
                return i in self.graph and n-1 == self.graph[i][-1]
            
            if i == n and rem == 0:
                return True
            if i >= n:
                return False
            
            for j in self.graph[i][::-1]:
                if dfs(j+1, rem-1):
                    return True
                
        
        return dfs()
    
    def expand_around(self, s, i):
        l = i //2
        r = (i + 1)//2
        n = len(s)
        
        while l >= 0 and r < n  and s[l] == s[r]:
            self.graph[l].append(r)
            l -= 1
            r += 1
class Solution:
    def minimumChanges(self, s: str, k: int) -> int:
        n=len(s)
        @cache
        def changes(i,j,d):
            if j-i<=d: return 0
            return changes(i+d,j-d,d)+sum(s[i+x]!=s[j-d+x] for x in range(d))
        @cache
        def semi_pal(i,j):
            l=j-i
            return min((changes(i,j,d) for d in range(1,l) if l%d==0), default=float('inf'))
        @cache
        def f(n,k):
            if k==0: return 0 if n==0 else float('inf')
            if n==0: return float('inf')
            return min(f(x,k-1)+semi_pal(x,n) for x in range(n))
        return f(n,k)
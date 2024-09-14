class Solution:
    def maxPossibleScore(self, start: List[int], d: int) -> int:
        start.sort()
        l, r = 0, start[-1]-start[0]+d
        n = len(start)
        ans = 0
        def check(m):
            s = start[0]
            for i in range(1,n):
                s += m
                if s > start[i]+d:
                    return False
                elif s < start[i]:
                    s = start[i]
            return True
            
        while l <= r:
            m = l + (r-l)//2
            if check(m):
                ans = m
                l = m+1
            else:
                r = m-1
        return ans
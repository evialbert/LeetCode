class Solution:
    def minTravelTime(self, l: int, n: int, k: int, position: List[int], time: List[int]) -> int:
        prevtime = [0]
        for t in time:
            prevtime.append(prevtime[-1]+t)
        @cache
        def dp(i,r,speed):
            if i == n-1: return 0 if r == 0 else inf
            res = inf
            for merge in range(min(r+1,n-2-i+1)):
                dist = position[i+1+merge] - position[i]
                res = min(res,speed*dist+dp(i+1+merge,r-merge,prevtime[i+2+merge]-prevtime[i+1]))
            return res
        return dp(0,k,time[0])
            


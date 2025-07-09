class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        gp=[0]*(len(startTime)+1)
        gp[0],gp[-1]=startTime[0],eventTime-endTime[-1]
        for i in range(len(startTime)-1):#storing all gaps of len(n+1)
            gp[i+1]=startTime[i+1]-endTime[i]
        l=mx=cur=0
        for r in range(len(gp)):#finding max window of size k in gaps
            if r-l>k:
                cur-=gp[l]
                l+=1
            cur+=gp[r]
            mx=max(mx,cur)
        return mx
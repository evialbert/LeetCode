class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:
        prev = 0
        leng = len(days)
        minarr = [float('inf')]*leng
        mc = min(costs)
        
        for i in range(leng):

            minarr[i] = min(minarr[i],prev+mc)
            day = days[i]
            
            #7 day
            limit = min(day+6,days[-1])
            reach = bisect.bisect_right(days,limit)-1
            minarr[reach] = min(prev+costs[1],minarr[reach])

            #30 day
            curr = i
            limit = min(day+29,days[-1])
            reach = bisect.bisect_right(days,limit)-1
            minarr[reach] = min(prev+costs[2],minarr[reach])

            prev = minarr[i]

        return minarr[-1]
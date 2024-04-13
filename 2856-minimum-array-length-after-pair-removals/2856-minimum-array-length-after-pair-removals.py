class Solution:
    def minLengthAfterRemovals(self, nums):
        ans, dict1 = [], Counter(nums)

        for key,val in dict1.items():
            heapq.heappush(ans,-val)

        while len(ans) > 1:
            a = -heapq.heappop(ans)
            b = -heapq.heappop(ans)

            if a-1 > 0:
                heapq.heappush(ans,-a+1)
            if b-1 > 0:
                heapq.heappush(ans,-b+1)

        return -sum(ans)
class Solution:
    def maxKelements(self, nums: List[int], k: int) -> int:
        
        heap=[-val for val in nums]

        heapify(heap)
        ans=0
        
        while k:
            mx=-heappop(heap)
            ans+=mx
            heappush(heap,-math.ceil(mx/3))
            k-=1
        return ans
            
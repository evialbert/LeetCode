class Solution:
    def findMaxSum(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        arr = sorted([[i,j] for i,j in zip(nums1,nums2)])
        _heap = []
        dic = {}
        total = 0
        for i, j in arr:
            prev = total
            total += j
            heappush(_heap,j)
            if len(_heap) > k:
                total -= heappop(_heap)
            if not i in dic:
                dic[i] = prev
        
        return [dic[i] for i in nums1]
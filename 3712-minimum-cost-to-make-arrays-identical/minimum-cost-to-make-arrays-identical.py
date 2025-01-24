class Solution:
    def minCost(self, arr: List[int], brr: List[int], k: int) -> int:
        if arr == brr:
            return 0
        res2 = 0
        for i,v in enumerate(arr):
            res2 += abs(v - brr[i])
        arr.sort()
        brr.sort()
        res = k
        for i,v in enumerate(arr):
            res += abs(v - brr[i])

        return min(res2,res)
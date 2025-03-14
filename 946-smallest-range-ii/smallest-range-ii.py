class Solution:
    def smallestRangeII(self, nums: List[int], k: int) -> int:
        
        # Remove duplicates and sort
        arr = sorted(list(set(nums)))
        
        res = arr[-1] - arr[0]
        for i in range(len(arr) - 1):
            res = min(res, max(arr[i] + k, arr[-1] - k) - min(arr[0] + k, arr[i + 1] - k))
        
        return res
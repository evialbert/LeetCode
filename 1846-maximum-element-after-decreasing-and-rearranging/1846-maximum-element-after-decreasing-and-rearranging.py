class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        if len(arr) <= 1:
            return 1
        
        if arr[0] != 1:
            arr[0] = 1
        ans = 1
        for i in range(1, len(arr)):
            if arr[i] - arr[i - 1] > 1:
                arr[i] = arr[i - 1] + 1
            ans = arr[i]
        
        return ans
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        res = 1
        l = 0
        r = 1
        isGreater = True
        while r < len(arr):
            if (isGreater and arr[r - 1] < arr[r]) or (not isGreater and arr[r - 1] > arr[r]):
                isGreater = not isGreater
            elif arr[r - 1] == arr[r]:
                l = r
            else:
                isGreater = not arr[r - 1] < arr[r]
                l = r - 1
            res = max(res, r - l + 1)
            r += 1
        return res
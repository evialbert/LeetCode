class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        n = len(arr)
        inv, freq, i = n/min(15, n), [], 0
        while (round(i) < n):
            freq += [arr[round(i)]]
            i += inv
        return mode(freq)
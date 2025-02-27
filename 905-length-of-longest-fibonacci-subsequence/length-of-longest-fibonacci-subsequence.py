class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        lookup = dict() ; res = 0
        for pos, num in enumerate(arr):
            lookup[num] = defaultdict(lambda: 2)
            for prev_pos in range (pos-1, -1, -1):
                prev = arr[prev_pos]
                prev2 = num - prev
                if prev2 >= prev:   break
                if prev2 in lookup:
                    lookup[num][prev] = lookup[prev][prev2] + 1
                    res = max(res, lookup[num][prev])
        return res
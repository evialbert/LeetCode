class Solution:
    def putMarbles(self, weights: List[int], k: int) -> int:
        d = []
        for i in range(len(weights) - 1):
            d.append(weights[i] + weights[i + 1])
        d.sort()
        return sum(d[len(weights) - k:]) - sum(d[:k - 1])
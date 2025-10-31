class Solution:
    def distinctPoints(self, S, K):
        dirmap = {"L": -1, "R": +1, "U": -1j, "D": +1j}
        P = list(accumulate((dirmap[c] for c in S), initial=0))
        seen = {P[i] - P[i - K] for i in range(K, len(P))}
        return len(seen)
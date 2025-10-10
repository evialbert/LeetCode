class Solution:
    def score(self, A: List[str], X: str) -> int:
        wilds = 0
        countL = [0] * 10
        countR = [0] * 10
        for x, y in A:
            if x == y == X:
                wilds += 1
            elif x == X:
                countL[ord(y) - 97] += 1
            elif y == X:
                countR[ord(x) - 97] += 1

        pairs = free = 0
        for count in [countL, countR]:
            s = sum(count)
            m = max(count)
            p = min(s - m, s // 2)
            pairs += p
            free += s - 2 * p
        
        used = min(wilds, free)
        wilds -= used
        extra = min(pairs, wilds // 2)
        return pairs + used + extra
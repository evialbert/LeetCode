class Solution:
    def maxSubstringLength(self, s: str, k: int) -> bool:
        first = collections.defaultdict(int)
        last = collections.defaultdict(int)
        for i in range(len(s)):
            if s[i] not in first:
                first[s[i]] = i
        for j in range(len(s) - 1, -1, -1):
            if s[j] not in last:
                last[s[j]] = j
        cand = []
        for c in first:
            i = first[c]
            j = last[s[i]]
            m = i
            while m < j:
                if first[s[m]] < i:
                    break
                j = max(j, last[s[m]])
                m += 1
            if j == m:
                if i != 0 or j != len(s) - 1:
                    cand.append((i, j))
        cand.sort(key=lambda x: (x[1], -x[0]))

        last = -1
        res = 0
        for s, e in cand:
            if s > last:
                res += 1
                last = e
        return True if res >= k else False
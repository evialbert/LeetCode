class Solution:
    def longestCommonPrefix(self, words: list[str]) -> list[int]:
        n = len(words)
        if n <= 2:
            return [0] * n
        def lcp(w1, w2):
            m = min(len(w1), len(w2))
            i = 0
            while i < m and w1[i] == w2[i]:
                i += 1
            return i
        c = [lcp(words[i], words[i+1]) for i in range(n-1)]
        pre = [0] * (n-1)
        pre[0] = c[0]
        for i in range(1, n-1):
            pre[i] = max(pre[i-1], c[i])
        suf = [0] * (n-1)
        suf[-1] = c[-1]
        for i in range(n-3, -1, -1):
            suf[i] = max(suf[i+1], c[i])
        d = [0] * n
        for k in range(1, n-1):
            d[k] = lcp(words[k-1], words[k+1])
        answer = [0] * n
        for k in range(n):
            if k == 0:
                answer[k] = suf[1]
            elif k == n-1:
                answer[k] = pre[n-3]
            else:
                left = pre[k-2] if k-2 >= 0 else 0
                right = suf[k+1] if k+1 <= n-2 else 0
                answer[k] = max(left, d[k], right)
        return answer
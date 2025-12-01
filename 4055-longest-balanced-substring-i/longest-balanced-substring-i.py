class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        ans = 0
        a = ord('a')
        for i in range(n):
            counts = [0]*26
            for j in range(i,n):
                counts[ord(s[j]) - a] += 1
                mx = 0
                distinct = 0
                ok = True
                for v in counts:
                    if v > 0:
                        distinct += 1
                        if mx == 0:
                            mx = v
                        elif v != mx:
                            ok = False
                            break
                if ok and distinct > 0:
                    ans = max(ans, j-i+1)
        return ans
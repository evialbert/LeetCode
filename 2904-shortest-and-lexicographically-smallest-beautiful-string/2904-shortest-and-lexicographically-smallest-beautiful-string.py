class Solution:
    def shortestBeautifulSubstring(self, s, k):
        n, count, left, res = len(s), 0, 0, []

        for right in range(n):
            if s[right] == "1":
                count += 1

            while count > k:
                count -= s[left] == "1"
                left += 1

            if count == k:
                res.append(s[left:right+1])

        ans = list(set([i.rstrip("0").lstrip("0") for i in res]))

        return min(ans,key = lambda x:(len(x),x)) if ans else ""
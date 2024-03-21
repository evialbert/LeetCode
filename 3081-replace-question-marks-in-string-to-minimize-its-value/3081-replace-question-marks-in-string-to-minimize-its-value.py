class Solution:
    def minimizeStringValue(self, s: str) -> str:
        counter = {x: 0 for x in "abcdefghijklmnopqrstuvwxyz?"}
        for c in s:
            counter[c] += 1
        replacement = counter["?"]
        del counter["?"]
        l = []
        for k in counter:
            heapq.heappush(l, (counter[k], k))
        letters = []
        for i in range(replacement):
            nb, letter = heapq.heappop(l)
            letters.append(letter)
            heapq.heappush(l, (nb + 1, letter))
        letters.sort()
        res = ""
        i = 0
        for c in s:
            if c == "?":
                res += letters[i]
                i += 1
            else:
                res += c
        return res
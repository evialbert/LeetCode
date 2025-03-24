class Solution:
    def substringXorQueries(self, s: str, qs: List[List[int]]) -> List[List[int]]:
        d, n = dict(), len(s)
        for i in range(n):
            for j in range(i, min(i+32, n)):
                key = int(s[i:j+1], 2)
                if key not in d:
                    d[key] = [i, j]
                else:
                    ex = d[key]
                    if ex[0] > i or j-i < ex[1]-ex[0]:
                        d[key] = [i, j]
        result = []
        for i in range(len(qs)):
            key = qs[i][0] ^ qs[i][1]
            if key in d:
                result.append(d[key])
            else:
                result.append([-1, -1])
        return result
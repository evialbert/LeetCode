class Solution:
    def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
        s1 = s1.split(' ')
        s2 = s2.split(' ')
        d = dict()
        res = []
        for i in s1:
            d[i] = d.get(i, 0) +1
        for i in s2:
            d[i] = d.get(i, 0) +1
        for key, val in d.items():
            if val == 1:
                res.append(key)
        # print(list(r))
        return res
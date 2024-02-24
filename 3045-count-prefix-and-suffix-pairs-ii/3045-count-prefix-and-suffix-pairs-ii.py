class Trie:
    def __init__(self):
        self.root = {}
    def insert(self, w, reverse=False):
        cur = self.root
        indices = set()
        for c in w:
            if c in cur:
                cur = cur[c]
            else:
                cur[c] = {}
                cur = cur[c]
            if 'end' in cur:
                indices.add(cur['end'])
        cur['end'] = w[::-1] if reverse else w
        return indices

class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        pref = Trie()
        suf = Trie()
        ct = defaultdict(int)
        res = 0
        for w in words:
            indices1 = pref.insert(w)
            rw = w[::-1]
            indices2 = suf.insert(rw, True)
            # len(indices1) and len(indices2) are biunded by len(w)
            for j in indices1:
                if j in indices2:
                    res += ct[j]
            ct[w] += 1
        return res
class Solution:

    def __init__(self):
        self.tree = []
        self.n = 0
        self.inds = {}
        self.vals = []
        
        
    def update(self, i, val):
        self.tree[self.n + i] = val
        self.vals[i] = val
        k = self.n + i
        while k > 1:
            self.tree[k>>1] = max(self.tree[k], self.tree[k^1])
            k >>= 1
    
    def query(self, i, j):
        k, m = self.n + i, self.n + j
        res = 0
        while k < m:
            if (k & 1):
                res = max(res, self.tree[k])
                k += 1
            if (m & 1):
                m -= 1
                res = max(res, self.tree[m])
            k >>= 1
            m >>= 1
        return res
    
    def maxEnvelopes(self, envelopes:list) -> int:
        stX = sorted(list(set([x[0] for x in envelopes])))
        self.n = len(stX)
        tab = {stX[i]: i for i in range(self.n)}
        self.tree = [0]*(2*self.n)
        self.vals = [0]*(self.n)
        stY = sorted(list(set([x[1] for x in envelopes])))
        ans = 0
        for x in envelopes:
            if x[1] not in self.inds.keys():
                self.inds[x[1]] = [tab[x[0]]]
            else:
                self.inds[x[1]].append(tab[x[0]])
        for x in stY:
            qs = {}
            for idx in self.inds[x]:
                q = self.query(0, idx)
                qs[idx] = q + 1
                ans = max(ans, q + 1)
            for idx in self.inds[x]:
                self.update(idx, qs[idx])
        return ans
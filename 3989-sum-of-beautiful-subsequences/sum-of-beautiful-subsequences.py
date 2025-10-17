class Solution:
    def totalBeauty(self, nums: list[int]) -> int:
        def divisors(x):
            ps = []
            while x > 1:
                p = spf[x]
                c = 0
                while x%p == 0:
                    x //= p
                    c += 1
                ps.append((p,c))
            ds = [1]
            for p, e in ps:
                mult = 1
                add = []
                for _ in range(e):
                    mult *= p
                    for v in ds:
                        add.append(v*mult)
                ds += add
            return ds
        def cnt(seq):
            if not seq:
                return 0
            cs = sorted(set(seq))
            rk = {v:i+1 for i,v in enumerate(cs)}
            m = len(cs)
            bit = [0]*(m+1)
            ans = 0
            for v in seq:
                s = 0
                i = rk[v]-1
                while i > 0:
                    s = (s+bit[i])%(10**9+7)
                    i -= i&-i
                w = (1+s)%(10**9+7)
                ans = (ans+w)%(10**9+7)
                i = rk[v]
                while i <= m:
                    bit[i] = (bit[i]+w)%(10**9+7)
                    i += i&-i
            return ans
        
        mx = max(nums)
        spf = list(range(mx+1))
        for i in range(2, int(mx**0.5)+1):
            if spf[i] == i:
                step = i
                for j in range(i**2, mx+1, step):
                    if spf[j] == j:
                        spf[j] = i
        mp={}
        for v in nums:
            for d in divisors(v):
                mp.setdefault(d, []).append(v//d)
        cntg = {}
        for g, seq in mp.items():
            cntg[g] = cnt(seq)
        keys = sorted(cntg.keys(), reverse=True)
        exact = {}
        for g in keys:
            s = cntg[g]
            j = g*2
            while j <= mx:
                if j in exact:
                    s -= exact[j]
                j += g
            exact[g] = s%(10**9+7)
        res = 0
        for g, v in exact.items():
            res += g*v
        return res%(10**9+7)
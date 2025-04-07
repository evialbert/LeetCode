class Solution:
    def maxProduct(self, nums: List[int], k: int, limit: int) -> int:
        ans = -1 
        n = len(nums)
        ppos = set()
        pneg = set()
        zpos = set()
        zneg = set()
        for i, x in enumerate(nums): 
            pos = set()
            neg = set()
            if x <= limit: pos.add((x, x))
            for s, p in ppos: 
                ss = s - x
                pp = p * x
                if pp <= limit: neg.add((ss, pp))
            for s, p in pneg: 
                ss = s + x
                pp = p * x
                if pp <= limit: pos.add((ss, pp))
            ppos |= pos
            pneg |= neg 
            pos = {(x, x == 0)}
            neg = set()
            for s, tf in zpos: 
                ss = s - x
                tt = tf or x == 0 
                neg.add((ss, tt))
            for s, tf in zneg: 
                ss = s + x
                tt = tf or x == 0
                pos.add((ss, tt))
            zpos |= pos
            zneg |= neg
        for s, p in ppos | pneg: 
            if s == k: ans = max(ans, p)
        for s, tf in zpos | zneg: 
            if s == k and tf: ans = max(ans, 0)
        return ans 
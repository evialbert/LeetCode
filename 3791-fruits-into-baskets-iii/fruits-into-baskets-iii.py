
class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        t = [0]*4*len(baskets)

        def build(v, tl, tr):
            if (tl == tr): t[v]=baskets[tl]
            else:
                tm = (tl + tr) // 2
                build(v*2, tl, tm)
                build(v*2+1, tm+1, tr)
                t[v] = max(t[v*2] , t[v*2+1])
        build(1,0,len(baskets)-1)

        def update(v, tl, tr, pos, new_val):
            if (tl == tr): t[v] = new_val
            else:
                tm = (tl + tr) // 2
                if (pos <= tm):
                    update(v*2, tl, tm, pos, new_val)
                else:
                    update(v*2+1, tm+1, tr, pos, new_val)
                t[v] = max(t[v*2] , t[v*2+1])

        def get_first(v, tl, tr, l, r, x):
            if(tl > r or tr < l): return -1
            if(t[v] <= x): return -1
            if (tl== tr): return tl

            tm = tl + (tr-tl)//2
            left = get_first(2*v, tl, tm, l, r, x)
            if(left != -1): return left
            return get_first(2*v+1, tm+1, tr, l ,r, x)
        
        res=0
        for n in fruits:
            i =get_first(1,0,len(baskets)-1,0, len(baskets)-1, n-1)
            if i == -1:
                res+=1
            else:
                update(1,0,len(baskets)-1,i,0)
        return res
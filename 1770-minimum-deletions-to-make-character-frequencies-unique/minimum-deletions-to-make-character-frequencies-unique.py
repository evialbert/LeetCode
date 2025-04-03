class Solution:
    def minDeletions(self, s: str) -> int:
        counts=Counter(s)
        res=0
        set1=set()
        for i in counts:
            frec=counts[i]
            if frec  in set1:
                while frec in set1 and frec>0: 
                    frec-=1
                    res+=1
                    
            set1.add(frec)         
        return res
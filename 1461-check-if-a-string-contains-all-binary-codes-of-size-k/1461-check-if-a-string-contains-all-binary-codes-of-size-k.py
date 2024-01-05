class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        total=2**k
        seen=set()
        curr_sub=0
        mask=total-1
        for x in range(len(s) ):
            curr_sub=((curr_sub<<1)& mask) | (int(s[x]))
            #print("c_rr",curr_sub)
            if x>=k-1:
                seen.add(curr_sub)
                #print(seen)
        return True if len(seen)==total else False
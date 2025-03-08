class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        l1=len(p)
        l2=len(s)
        if l1>l2:
            return []
        dct1=defaultdict(int)
        for c in p:
            dct1[c]+=1
        ld=len(dct1)
        ans=[]
        i1=0
        while i1<l1:
            c=s[i1]
            if c in dct1:
                tmp=dct1[c]
                if tmp==1:
                    ld-=1
                elif tmp==0:
                    ld+=1
                dct1[c]=tmp-1
            i1+=1
        if not ld:
            ans.append(0)
        i0=0
        while i1<l2:
            c=s[i1]
            if c in dct1:
                tmp=dct1[c]
                if tmp==1:
                    ld-=1
                elif tmp==0:
                    ld+=1
                dct1[c]=tmp-1
            c=s[i0]
            if c in dct1:
                tmp=dct1[c]
                if tmp==0:
                    ld+=1
                elif tmp==-1:
                    ld-=1
                dct1[c]=tmp+1
            i0+=1
            if not ld:
                ans.append(i0)
            i1+=1
        return ans
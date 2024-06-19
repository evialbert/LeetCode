class Solution:
    def valueAfterKSeconds(self, n: int, k: int) -> int:
        a=[1 for i in range(n)]
        num=(10**9)+7
        def f(li):
            
            c=li[0]
            for i in range(1,len(li)):
                c+=li[i]%num
                li[i]=c
            return li
        for i in range(k):
            a=f(a)
        return a[-1]%num
            
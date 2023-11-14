class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        dic={}
        for i in range(0,len(s)):
            if s[i] in dic:
                dic[s[i]][1]=i
            else:
                dic[s[i]]=[i,0]
        count=0
        for k,value in dic.items():
            ss=set()
            for i in range(value[0]+1,value[1]):
                ss.add(s[i])
            count=count+len(ss)
        return count
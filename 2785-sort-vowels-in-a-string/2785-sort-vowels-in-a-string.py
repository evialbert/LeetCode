class Solution:
    def sortVowels(self, s: str) -> str:
        s=list(s)
        mp=[]
        for i in range(len(s)):
            if s[i] in ('a', 'e', 'i', 'o', 'u','A','E','I','O','U'):
                mp.append(s[i])
                s[i]='0'
        mp.sort()
        j=0
        for i in range(len(s)):
            if s[i]=='0':
                s[i]=mp[j]
                j+=1
        print(s)
        return ''.join([str(elem) for elem in s])
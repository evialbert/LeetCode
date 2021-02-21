class Solution:
    def freqAlphabets(self, s: str) -> str:
        k=''
        i=0
        while i<len(s):
            try:
                if s[i+2]=='#':
                    k+=chr(96+int(s[i:i+2]))
                    i+=2
                else:
                    k+=chr(96+int(s[i]))    
            except:
                k+=chr(96+int(s[i]))
            i+=1
        return (k)
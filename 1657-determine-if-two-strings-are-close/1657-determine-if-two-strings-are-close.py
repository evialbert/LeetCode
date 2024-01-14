class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        c1=Counter(word1)
        c2=Counter(word2)
        
        n1=Counter(c1.values())
        n2=Counter(c2.values())
        
        return c1==c2 or (n1==n2 and set(word1)==set(word2))
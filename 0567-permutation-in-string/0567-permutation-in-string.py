class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        h1=Counter(s1)
        n=len(s1)
        
        for i in range(len(s2)-len(s1)+1):
            h2 = Counter(s2[i:i+n])
            if h1==h2:
                return True
        return False
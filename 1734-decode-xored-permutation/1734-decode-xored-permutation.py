class Solution:
    def decode(self, encoded: List[int]) -> List[int]:
        total = 0
        a1an = 0
        n = len(encoded) + 1
        for i in range(len(encoded)):
            a1an ^= encoded[i]
            total ^= a1an
        
        nForAll = 0
        for i in range(1, n+1):
            nForAll ^= i
               
        a = [nForAll ^ total]
        
        for i in range(len(encoded)):
            a.append(encoded[i]^a[-1])
            
        return a
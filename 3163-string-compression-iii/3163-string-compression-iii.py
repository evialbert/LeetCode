class Solution:
    def compressedString(self, word: str) -> str:
        if not word:
            return ""
        
        compstr = []
        n = len(word)
        i = 0
        
        while i < n:
            curr = word[i]
            c = 0
            
            while i < n and word[i] == curr and c < 9:
                c += 1
                i += 1
            compstr.append(f"{c}{curr}")
        return ''.join(compstr)

class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        l = sentence.split()
        s =''
        for i in range(len(l)):
            for j in dictionary:
                if l[i].startswith(j):
                    l[i] = j
        for i in l:
            s=s+i+" "
            
        s=s.strip()
        return s
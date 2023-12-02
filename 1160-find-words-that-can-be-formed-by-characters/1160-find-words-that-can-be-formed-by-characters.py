class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        length=[]
        for i in words:
            for j in i:
                if chars.count(j) < i.count(j): 
                    break
            else:
                length.append(len(i))
        return sum(length)
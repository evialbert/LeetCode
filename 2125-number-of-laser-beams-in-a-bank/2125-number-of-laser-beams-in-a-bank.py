class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        counts = []
        res = 0 
        prev = 0 
        for b in bank:
            c = b.count('1')
            if c != 0:
                res += c*prev
                prev = c
        return res
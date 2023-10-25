class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        st = bin(k-1)[2:].zfill(n-1)
        ret = False
        for s in st:
            if s == "1":
                ret = not ret

        return int(ret)
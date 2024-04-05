class Solution:
    def makeGood(self, s: str) -> str:
        s_copy = s[::]
        run = True
        while run:
            run = False
            i = 0
            while i < len(s_copy) - 1:
                if s_copy[i] != s_copy[i+1] and (s_copy[i] == s_copy[i+1].upper() or s_copy[i] == s_copy[i+1].lower()):
                    s_copy = s_copy[:i] + s_copy[i+2:]
                    run = True

                else:
                    i += 1 
        return s_copy
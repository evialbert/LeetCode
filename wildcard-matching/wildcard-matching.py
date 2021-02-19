class Solution:
    # @param {string} s
    # @param {string} p
    # @return {boolean}
    def isMatch(self, s, p):
        starp = -1
        stars = -1
        inp = 0
        ins = 0
        while ins < len(s):
            if inp != len(p):
                if p[inp] == '*':
                    starp = inp
                    stars = ins
                    inp += 1
                    continue
                if p[inp] == s[ins] or p[inp] == '?':
                    inp += 1
                    ins += 1
                    continue
            if starp != -1:
                inp = starp + 1
                stars += 1
                ins = stars
                continue
            return False
        while inp < len(p) and p[inp] == '*':
            inp += 1
        return inp == len(p)
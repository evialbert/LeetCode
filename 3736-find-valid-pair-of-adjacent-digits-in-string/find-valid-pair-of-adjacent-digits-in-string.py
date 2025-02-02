
class Solution:
    def findValidPair(self, s):
        return (lambda x: x[0] if x else '')((lambda cc: [s[i:i+2] for i in range(len(s) - 1) if s[i] != s[i + 1] and cc[s[i]] == int(s[i]) and cc[s[i + 1]] == int(s[i + 1])])(Counter(s)))

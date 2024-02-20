class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        cnt = 0
        for i in range(len(words)):
            for j in range(i+1,len(words)):
                out = self.isPrefixAndSuffix(words[i],words[j])
                cnt = cnt + out
        return cnt

    def isPrefixAndSuffix(self,s1,s2):
        if s2.startswith(s1) and s2.endswith(s1):
            return 1
        else:
            return 0
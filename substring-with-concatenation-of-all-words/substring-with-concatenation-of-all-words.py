class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        if not words: return []
        wl = len(words[0]); n = len(words); totalLth = wl * n 
        res = []
        
        m = collections.Counter(words)
        
        for i in range(len(s) - totalLth + 1):
            seen = collections.defaultdict(int)
            for j in range(i, i+totalLth, wl):
                w = s[j:j+wl]
                if w not in m:
                    break
                else:
                    seen[w] += 1
            if seen == m:
                res.append(i)
        return res
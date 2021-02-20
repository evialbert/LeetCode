class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
	
        if set(s) > set(''.join(wordDict)):
            return []
        
        def dfs(s,l):
            for word in wordDict: 
                if s==word:
                    out.append(" ".join(l+[word]))
                elif s.startswith(word):
                    dfs(s[len(word):],l+[word])
                        
        out = []
        dfs(s,[])
        
        return out
class Solution:
    def partition(self, s: str) -> List[List[str]]:
      
	   # check if the string is palindrome
        def isPalin(word: str) -> bool:
            if not word:
                return False
            return word == word[::-1]
        res = []
        if not s:
            return []
			
		# if the string s itself is a palindrome string
		# append it as a result
        if isPalin(s):
            r = [s]
            res.append(r)    
        lens = len(s)

        for i in range(lens):
            if isPalin(s[:i]):
                prefix = [s[:i]]
                
				# palindrom partition the rest of the string s
				# append the prefix to each partion of the rest string
                restList = [ prefix + r for r in self.partition(s[i:]) ]
                res += restList
        return res
   
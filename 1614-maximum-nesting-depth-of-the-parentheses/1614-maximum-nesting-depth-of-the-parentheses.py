class Solution:
    def maxDepth(self, s: str) -> int:
        maxBrace,currBrace = 0,0 
		# One to keep track of the max val the other to keep track of current number of open braces
        n = len(s)
        for i in range(n):
            if s[i] == '(':
                currBrace+=1
            elif s[i] == ')':
				# If we encounter the first closing braces we can say that a sub equation has come to an end so we check is it is the max
                maxBrace = max(currBrace,maxBrace)
                currBrace-=1
        return maxBrace
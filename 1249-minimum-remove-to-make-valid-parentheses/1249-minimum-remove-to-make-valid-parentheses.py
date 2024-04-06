class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        for i in range(len(s)):
            if s[i] in '()':
                if s[i] == ')' and len(stack) and s[stack[-1]]  == '(':
                    stack.pop()
                else:
                    stack.append(i)
        for i in stack:
            s = s[:i] + '#' +s[i + 1:]
        s = s.replace('#','')
        return s
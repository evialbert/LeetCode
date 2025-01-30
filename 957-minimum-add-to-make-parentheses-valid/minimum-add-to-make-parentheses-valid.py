class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        closed = 0
        opened = 0
        for i in s:
                if i == '(':
                    opened += 1
                    print(i)
                    print(opened)
                elif i == ')' and opened > 0:
                    opened -= 1
                    print(i)
                    print(opened)
                elif i == ')' and opened <= 0:
                    closed += 1
                    print(i)
                    print(opened)
        return opened + closed
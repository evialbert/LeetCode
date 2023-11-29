class Solution:
    def checkValidString(self, s: str) -> bool: 

        memo = {}

        def valid(open, ind):
            if open < 0: return False
            if ind == len(s): return open == 0

            if (open, ind) in memo: return memo[(open, ind)]

            if s[ind] == '(': memo[(open, ind)] = valid(open + 1, ind + 1)
            if s[ind] == ')': memo[(open, ind)] = valid(open - 1, ind + 1)
            if s[ind] == '*': memo[(open, ind)] = valid(open + 1, ind + 1) or valid(open - 1, ind + 1) or valid(open, ind + 1)

            return memo[(open, ind)]

        return valid(0, 0)
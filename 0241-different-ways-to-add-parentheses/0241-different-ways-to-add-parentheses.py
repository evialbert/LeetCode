class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        def compute(s):
            n = len(s)
            if n < 3:
                return [int(s)] if n > 0 else []
            ans = []
            for i, c in enumerate(s):
                if c in '+-*':
                    left = compute(s[:i])
                    right = compute(s[i+1:])
                    for a in left:
                        for b in right:
                            ans.append(a+b if c == '+' else a-b if c == '-' else a*b)
            return ans
        return compute(expression)
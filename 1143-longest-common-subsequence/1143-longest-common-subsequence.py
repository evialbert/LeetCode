class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        prev = [0] * (len(text2) + 1)

        for a in text1:
            current = [0]
            for j, b in enumerate(text2):
                if a == b:
                    value = prev[j] + 1
                else:
                    value = max(current[-1], prev[j + 1])
                current.append(value)
            prev = current
        
        return prev[-1]
class Solution:
    # Precompute the next character for each alphabet letter
    nextChar = {chr(i): chr(i + 1) if chr(i) != 'z' else 'a' for i in range(97, 123)}
    
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        m, n = len(str1), len(str2)
        i, j = 0, 0
        
        # Continue while there are characters left in both strings and there's still hope to complete str2
        while i < m and j < n and m - i >= n - j:
            current, target = str1[i], str2[j]
            
            # Increment j if the current character of str2 can match the current or next character of str1
            if target == current or target == self.nextChar[current]:
                j += 1
            i += 1
        
        # Return True if all characters of str2 are matched
        return j == n
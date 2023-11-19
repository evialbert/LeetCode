class Solution:
   #Time complexity: O(N)
   #Space complexity: O(1)
    def minimumSteps(self, s: str) -> int:
        l, r = 0, len(s) - 1
        ans = 0
        
        while l < r:
            while l < r and s[l] == '0':
                l += 1
            while l < r and s[r] == '1':
                r -= 1
            ans += r - l
            l += 1
            r -= 1
        return ans
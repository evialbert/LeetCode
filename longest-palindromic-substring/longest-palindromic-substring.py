class Solution:
    def longestPalindrome(self, s: str) -> str:
        n , start , end = len(s) , 0 , 0
        def expandFromMid(left , right):
            if not s or left > right: return 0
            while left >=0 and right < n and s[left] == s[right]:
                left -= 1
                right += 1
            return right - left - 1
        for i in range(n):
            case1 = expandFromMid(i , i)
            case2 = expandFromMid(i , i + 1)
            longest_case = max(case1 , case2)
            if longest_case > end - start:
                start = i - ((longest_case - 1) // 2)
                end = i + (longest_case // 2)        
        return s[start : end + 1]
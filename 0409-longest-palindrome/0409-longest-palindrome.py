class Solution:
    def longestPalindrome(self, s: str) -> int:
        d = Counter(s)
        
        odd = []
    

        c = 0
        for i in d.values():
            if i%2==0:
                c += i
            else:
                odd.append(i)
        
        if odd:
            c = c + sum(odd) - len(odd) + 1
        return c
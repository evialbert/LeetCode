class Solution:
    def smallestPalindrome(self, s: str) -> str:
        c=Counter(s)
        k=""
        a=""

        
        for i in sorted(c):

            k+=i*(c[i]//2)
            a+=i*(c[i]%2)
        l=k[::-1]
        k+=a
        k+=l
        return k
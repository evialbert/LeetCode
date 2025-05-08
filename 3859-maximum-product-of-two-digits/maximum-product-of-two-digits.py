class Solution:
    def maxProduct(self, n: int) -> int:
        nl = [int(d) for d in str(n)]
        nl.sort(reverse = True)
        return nl[0]*nl[1]
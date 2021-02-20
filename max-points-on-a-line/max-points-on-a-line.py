class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        ans = 0
        for i, (x0, y0) in enumerate(points): #reference 
            dupe = 1 #count of duplicates
            freq = dict() #frequency table 
            for x, y in points[i+1:]:
                if x0 == x and y0 == y: dupe += 1
                elif x0 == x: freq[0, inf] = 1 + freq.get((0, inf), 0)
                elif y0 == y: freq[inf, 0] = 1 + freq.get((inf, 0), 0)
                else: 
                    g = gcd(x-x0, y-y0)
                    x, y = (x-x0)//g, (y-y0)//g
                    if x < 0: x, y = -x, -y
                    freq[x, y] = 1 + freq.get((x, y), 0)
            ans = max(ans, dupe + max(freq.values(), default=0))
        return ans 
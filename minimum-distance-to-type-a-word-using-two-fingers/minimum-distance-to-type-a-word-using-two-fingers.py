class Solution:
    def minimumDistance(self, word: str) -> int:
        table = defaultdict(tuple)
        for i in range(26):
            c = chr(ord('A') + i)
            row, col = divmod(i, 6)
            table[c] = (row, col)
        n = len(word)
            
        def get_dist(c1, c2):
            if c1 == '#' or c2 == '#':
                return 0
            r1, c1 = table[c1]
            r2, c2 = table[c2]
            return abs(r1-r2) + abs(c1-c2)
        
        @lru_cache(None)
        def dp(i, f1, f2):
            if i == n:
                return 0
            c = word[i]
            d1, d2 = get_dist(c, f1), get_dist(c, f2)
            return min(d1 + dp(i + 1, c, f2), d2 + dp(i + 1, f1, c))
        
        return dp(0, '#', '#')
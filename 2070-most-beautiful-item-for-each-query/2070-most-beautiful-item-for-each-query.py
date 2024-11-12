class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort()
        n = len(items)
        res = []
        for i in range(1, n):
            items[i][1] = max(items[i][1], items[i - 1][1])

        for q in queries:
            l, r = 0, n - 1
            while l <= r:
                m = (l + r) >> 1
                p, b = items[m]
                if p > q: r = m - 1
                else: l = m + 1
            res.append(items[r][1] if r >= 0 else 0)
        return res
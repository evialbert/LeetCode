class Solution:
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int]) -> int:
        @cache
        def dfs(items) -> int:
            res = sum(items[i] * price[i] for i in range(len(items)))
            for s in special:
                if all(items[i] - s[i] >= 0 for i in range(len(items))):
                    items = [items[i] - s[i] for i in range(len(items))]
                    res = min(res, s[-1] + dfs(tuple(items)))
                    items = [items[i] + s[i] for i in range(len(items))]
            return res
        return dfs(tuple(needs))
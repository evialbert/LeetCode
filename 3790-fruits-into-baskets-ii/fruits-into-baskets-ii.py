class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        filled_baskets, total_baskets = 0, len(baskets)
        for fruit in fruits:
            for basket in baskets:
                if fruit <= basket:
                    filled_baskets += 1
                    baskets.remove(basket)
                    break
        return total_baskets - filled_baskets
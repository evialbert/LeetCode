class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort()
        triplets = []
        l, r = 0, len(piles) - 1
        while l < r:
            triplet = [piles[r], piles[r - 1], piles[l]]
            triplets.append(triplet)
            r -= 2
            l += 1
        count = 0

        for p in triplets:
            count += p[1]
        return count
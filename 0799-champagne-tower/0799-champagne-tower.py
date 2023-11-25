class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        row = (poured,)

        for _ in range(query_row):
            xs = chain((0,), (max(x - 1, 0) / 2 for x in row), (0,))
            row = map(sum, pairwise(xs))
        
        return min(list(row)[query_glass], 1)
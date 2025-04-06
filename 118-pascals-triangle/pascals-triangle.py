class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        n = numRows
        if n == 1:
            return [[1]]
        elif n == 2:
            return [[1], [1, 1]]
        else:
            triangle = [[1], [1, 1]]
            for i in range(2, n):
                new_row = [1]
                prev_row = triangle[i - 1]
                for j in range(1, i):
                    new_row.append(prev_row[j - 1] + prev_row[j])
                new_row.append(1)
                triangle.append(new_row)

        return triangle
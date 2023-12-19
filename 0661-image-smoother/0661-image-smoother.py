class Solution:
    def imageSmoother(self, img: List[List[int]]) -> List[List[int]]:
        m, n = len(img), len(img[0])
        S = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                ids = [(i-1,j-1),(i-1,j),(i-1,j+1),(i,j-1),(i,j),(i,j+1),(i+1,j-1),(i+1,j),(i+1,j+1)]
                nbrs = [img[i][j] for i,j in ids if 0 <= i < m and 0 <= j < n]
                S[i][j] = sum(nbrs) // len(nbrs)
        return S
class Solution:
    def minFlips(self, mat: List[List[int]]) -> int:
        mx, nx = len(mat), len(mat[0])
        bv = 1
        m = defaultdict(int)
        
        c = 0
        for i in range(mx):
            for j in range(nx):
                m[(i, j)] = bv
                
                if mat[i][j]:
                    c += bv
                bv *= 2
        if c == 0:
            return 0
        f = set()
        for i in range(mx):
            for j in range(nx):
                f.add(m[(i,j)] + m[(i+1,j)] + m[(i-1,j)] + m[(i,j+1)] + m[(i,j-1)])
        mvs = [999 for i in range(bv)]
        mvs[c] = 0
        moves = {c}
        while moves:
            c = moves.pop()
            k = mvs[c]
            for i in f:
                if mvs[c ^ i] > k + 1:
                    moves.add(c^i)
                    mvs[c^i] = 1 + k
        if mvs[0] < 999:
            return mvs[0]
        return -1
        

        
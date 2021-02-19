class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        self.ans = []
        self.n = n
        self.col = [False]*n
        self.diag, self.codiag = set(), set()
        board = [['.']*n for _ in range(n)]
        self.backTrack(board, 0)
        return self.ans
    
    def backTrack(self, board, r):
        if r == self.n:
            arr = [''.join(row) for row in board]
            self.ans.append(arr)
            return
        for c in range(self.n):
            if self.canPlace(r, c):
                board[r][c] = 'Q'
                self.col[c] = True
                self.diag.add(r+c); self.codiag.add(r-c)
                self.backTrack(board, r+1)
                # undo the move
                board[r][c] = '.'
                self.col[c] = False
                self.diag.remove(r+c); self.codiag.remove(r-c)
    
    def canPlace(self, r, c):
        return not (self.col[c] or r+c in self.diag or r-c in self.codiag)
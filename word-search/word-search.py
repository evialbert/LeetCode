class Solution:
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        # edge case
        if not board: return False
        r, c = len(board), len(board[0])
        for i in range(r):
            for j in range(c):
                if board[i][j] == word[0] and self.dfs(board, word, i, j):
                    return True
                    
        return False
                    
    def dfs(self, board, word, i, j):
        # all the letters are checked
        if len(word) == 0:
            return True
        if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]) or board[i][j] != word[0]:
            return False
        temp = board[i][j]
        # mark the visited cell
        board[i][j] = '#'
        res  = self.dfs(board, word[1:], i-1, j) or self.dfs(board, word[1:], i+1, j) \
               or self.dfs(board, word[1:], i, j-1) or self.dfs(board, word[1:], i, j+1)
        board[i][j] = temp
        return res
            

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        
        def hasRep(l):
            d = collections.Counter()
            for i in l:
                if i == ".": continue
                d[i] += 1
            for i in d:
                if d[i] >= 2:
                    return True
            return False
        
        def serializeBlock(board, r, c):
            # Makes the elements in a 3x3 block into a list
            # r and c specify the row and col of the starting point
            ret = []
            for i in range(3):
                for j in range(3):
                    ret.append(board[r+i][c+j])
            print(ret)
            return ret
            
        nrow, ncol = len(board), len(board[0])
        # Column-wise
        for c in range(ncol):
            if hasRep([board[i][c] for i in range(nrow)]): return False
        # 3x3 blocks
        for r in (0, 3, 6):
            for c in (0, 3, 6):
                if hasRep(serializeBlock(board, r, c)): return False
        # Row-wise
        for r in range(nrow):
            if hasRep(board[r]): return False
               
        return True
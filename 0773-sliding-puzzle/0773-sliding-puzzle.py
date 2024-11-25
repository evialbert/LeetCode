class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        
        def bt(i0: int, j0: int, step: int) -> None:
            state = tuple(board[0] + board[1])
            if state == target:
                state2min[state] = min(state2min[state], step)
                return
            if state2min[state] <= step: # before / equivalent ans is found
                return
            state2min[state] = step

            for ii, jj in [[0,1], [0,-1], [1,0], [-1,0]]:
                ti, tj = i0 + ii, j0 + jj
                if 0 <= ti < 2 and 0 <= tj < 3:
                    board[i0][j0], board[ti][tj] = board[ti][tj], board[i0][j0]
                    bt(ti, tj, step + 1)
                    board[i0][j0], board[ti][tj] = board[ti][tj], board[i0][j0]

        
        state2min = defaultdict(lambda: float('inf'))
        target = tuple([1,2,3,4,5,0])
        i0 = j0 = -1
        for i in range(2):
            for j in range(3):
                if board[i][j] == 0:
                    i0, j0 = i, j
        bt(i0, j0, 0)
        return -1 if target not in state2min else state2min[target]
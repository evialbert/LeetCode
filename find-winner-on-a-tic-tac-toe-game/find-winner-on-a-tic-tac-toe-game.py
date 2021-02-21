class Solution:
    def tictactoe(self, moves: List[List[int]]) -> str:
        if len(moves) < 5:
            if len(moves) == 0:
                return "Draw"
            else:
                return "Pending"
        
        #split the lists into each players moves
        
        playerA = [moves[x] for x in range(0, len(moves), 2)]
        playerB = [moves[x] for x in range(1, len(moves), 2)]

        
        winningStates = [[[0,0], [0,1], [0,2]], #top horizontal row
                         [[1,0], [1,1], [1,2]], #middle horizontal row
                         [[2,0], [2,1], [2,2]], #bottom horizontal row
                         [[0,0], [1,0], [2,0]], #left vertical row
                         [[0,1], [1,1], [2,1]], #middle vertical row
                         [[0,2], [1,2], [2,2]], #right vertical row
                         [[0,0], [1,1], [2,2]], #left diagonal
                         [[2,0], [1,1], [0,2]], #right diagonal
                        ]
        
        
        winningStatus = "Pending"
        
        if len(moves) == 9:
            winningStatus = "Draw"
        
        #if a winning state is inclusive of their moves, they're the winner
        
        
        for x in winningStates:
            if all([y in playerA for y in x]):
                winningStatus = "A"
                break
            if all([y in playerB for y in x]):
                winningStatus = "B"
                break
                
        return winningStatus
class Solution {
    int[][] directions = new int[][]{{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    
    public char[][] updateBoard(char[][] board, int[] click) {
        int row = click[0], col = click[1];
        int n = board.length, m = board[0].length;
        
        checkBoard(board, row, col, n, m); 

        return board;
    }
    // count the mines in the 8 adjacent cells
    public int explore(char[][] board, int row, int col, int n, int m) {  
        int mines = 0;
        for (int[] direction : directions){
            int r = direction[0] + row, c = direction[1] + col;
            if (r < 0 || c < 0 || r >= n || c >= m)
                continue;
            if (board[r][c] == 'M')
                mines++; 
        } 
        return mines;
    }
    
    public void checkBoard(char[][] board, int row, int col, int n, int m) {  
        if (row < 0 || col < 0 || row >= n || col >= m || board[row][col] != 'E' && board[row][col] != 'M')
            return; 
        if (board[row][col] == 'M'){ 
            board[row][col] = 'X';
            return;
        }
        // get the number of mines in the 8 adjacent cells
        int mines = explore(board, row, col, n, m);
        // if one of them is a mine, change the cell val to the numeber of adjacent mines and return
        if (mines > 0) { 
            board[row][col] = (char)(mines + '0');
            return;
        } 
        // at this point none of the 8 adjacent cells has a mine, so we explore all of them
        board[row][col] = 'B';
        for (int[] direction : directions)
            checkBoard(board, row + direction[0], col + direction[1], n, m); 
    }
}
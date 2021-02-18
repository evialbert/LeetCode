class Solution {
    private int[][] board;
    public void gameOfLife(int[][] board) {
        this.board = board;
        
        dfs(0, 0);
    }
    
    private void dfs(int i, int j) {
        if (i < 0 || i > board.length - 1 || j < 0 || j > board[i].length - 1)
            return;
        
        int status = calculcateNextState(i, j);
        if (j + 1 < board[i].length)
            dfs(i, j + 1);
        else
            dfs(i + 1, 0);
        board[i][j] = status;
    }
    
    
    
    private int calculcateNextState(int i, int j) {
        int next = getState(i, j + 1);
        int prev = getState(i, j - 1);
        int up = getState(i - 1, j);
        int down = getState(i + 1, j);
        int prevUp = getState(i - 1, j - 1);
        int nextUp = getState(i - 1, j + 1);
        int nextDown = getState(i + 1, j + 1);
        int prevDown = getState(i + 1, j - 1);
        
        int liveCells = 
            (next == 1 ? 1 : 0) +
            (prev == 1 ? 1 : 0) +
            (up == 1 ? 1 : 0) +
            (down == 1 ? 1 : 0) +
            (prevUp == 1 ? 1 : 0) +
            (nextUp == 1 ? 1 : 0) +
            (nextDown == 1 ? 1 : 0) +
            (prevDown == 1 ? 1 : 0);
        
        if (board[i][j] == 1) {
            if (liveCells < 2 || liveCells > 3)
                return 0;
            else
                return 1;
        } else {
            if (liveCells == 3)
                return 1;
            else 
                return 0;
        }
            
    }
    
    private int getState(int i, int j) {
        if (i < 0 || i > board.length - 1 || j < 0 || j > board[i].length - 1)
            return -1;
        else
            return board[i][j];
    }
}
class Solution {
    int LEFT = 0, RIGHT = 1, UP = 2, DOWN = 3, m = 0, n = 0;
    public boolean placeWordInCrossword(char[][] board, String word) {
        m = board.length;
        n = board[0].length;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // if found empty cell or match the first char: try to place
                if (board[i][j] == ' ' || board[i][j] == word.charAt(0)) {
                    // try to place dir: LEFT
                    if (j == n - 1 || board[i][j + 1] == '#') {
                        if (placeWord(board, word, i, j, 0, LEFT)) return true;
                    }
                    
                    // try to place dir: right
                    if (j == 0 || board[i][j - 1] == '#') {
                        if (placeWord(board, word, i, j, 0, RIGHT)) return true;
                    }
                    
                    // try to place dir: UP
                    if (i == m - 1 || board[i + 1][j] == '#') {
                        if (placeWord(board, word, i, j, 0, UP)) return true;
                    }
                    
                    // try to place dir: DOWN
                    if (i == 0 || board[i - 1][j] == '#') {
                        if (placeWord(board, word, i, j, 0, DOWN)) return true;
                    }
                }
            }
        }
        return false;
    }
    
    private boolean placeWord(char[][] board, String word, int i, int j, int index, int dir) {
        if (index == word.length()) {
            if (dir == LEFT && (j < 0 || board[i][j] == '#')) return true;
            else if (dir == RIGHT && (j >= n || board[i][j] == '#')) return true;    
            else if (dir == UP && (i < 0 || board[i][j] == '#')) return true;
            else if (dir == DOWN && (i >= m || board[i][j] == '#')) return true;
            else return false;
        }
        
        if (i < 0 || j < 0 || i == m || j == n) return false;
        if (board[i][j] == '#') return false;
        if (board[i][j] != ' ' && board[i][j] != word.charAt(index)) return false;
        
        if (dir == LEFT) return placeWord(board, word, i, j - 1, index + 1, dir);
        else if (dir == RIGHT) return placeWord(board, word, i, j + 1, index + 1, dir);
        else if (dir == UP) return placeWord(board, word, i - 1, j, index + 1, dir);
        else return placeWord(board, word, i + 1, j, index + 1, dir);
    }
}
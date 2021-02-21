class Solution {
     private int walking(char[][] board, int x, int y) {
         int N = 8;
         int[][] dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
 
         int count = 0;
         for(int[] dir: dirs) {
             for(int nextX = x + dir[0], nextY = y + dir[1];
                 nextX >= 0 && nextX < N && nextY >= 0 && nextY < N
                 && board[nextX][nextY] != 'B';
                 nextX += dir[0], nextY += dir[1]) {
                 if(board[nextX][nextY] == 'p') {
                     ++count;
                     break;
                 }
             }
 
         }
         return count;
     }
 
     public int numRookCaptures(char[][] board) {
         for(int i = 0; i < board.length; ++i) {
             for(int j = 0; j < board[i].length; ++j) {
                 if(board[i][j] == 'R') {
                     return walking(board, i, j);
                 }
             }
         }
 
         return 0;
     }
 }
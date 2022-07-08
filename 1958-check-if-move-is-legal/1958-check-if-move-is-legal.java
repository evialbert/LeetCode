class Solution {
    public boolean checkMove(char[][] board, int rMove, int cMove, char color) {
        int[][] dir = {{0, 1},{0, -1},{1, 0},{-1, 0},{1, 1},{-1, 1},{1, -1},{-1, -1}};
        char op = (color == 'W') ? 'B' : 'W';
        
        for(int i = 0; i < 8; i++){
            int xx = rMove + dir[i][0];
            int yy = cMove + dir[i][1];
            int rcount = 0;
            while(xx >= 0 && yy >= 0 && xx < 8 && yy < 8 && board[xx][yy] == op){
                xx += dir[i][0];
                yy += dir[i][1];
                rcount++;
            }
            
            if(rcount!=0 && xx>=0 && xx<8 && yy>=0 && yy<8 && board[xx][yy]==color)
                return true;
        }
        return false;
    }
}
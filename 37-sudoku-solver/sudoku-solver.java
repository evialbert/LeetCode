class Solution {
    public void solveSudoku(char[][] board) {
        solve(board);}
    boolean solve(char[][]board)
    { for(int i=0;i<board.length;i++)
    {for(int j=0;j<board.length;j++)
    { if(board[i][j] == '.')
    {for( char num ='1';num <='9';num++)
    {  if(isSafe(board,i,j,num))
    {board[i][j]=num;
    if(solve(board)) //found the ans
    return true;
    else
    //backtrack
     board[i][j]='.';
    } } return false;} }}
    return true; }
     boolean isSafe(char[][] board,int row,int col,char num)
    { // check the row
      for(int i=0;i<board.length;i++)
      { // check if the number is in the row
        if(board[i][col] == num)  return false;
         // check the column
       // check if the number is in the column
        if(board[row][i]== num) return false;
      }int sqrt=(int)(Math.sqrt(board.length));
      int rowStart=row - row % sqrt;
      int colStart=col - col % sqrt;
      for(int r=rowStart;r<rowStart + sqrt;r++)
      { for(int c=colStart;c<colStart + sqrt;c++)
       {if(board[r][c] == num)   return false; }
      }return true;
}
}
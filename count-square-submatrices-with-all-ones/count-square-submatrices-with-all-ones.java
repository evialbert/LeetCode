class Solution {
    public int countSquares(int[][] matrix) {
        int row = matrix.length;
        int col = matrix[0].length;
        int squares = 0;
        for(int i = 0 ; i < row; i++)
        {
            for(int j = 0 ; j < col ; j++)
            {
                if(matrix[i][j] != 0)
                {
                    if(i != 0 && j != 0)
                    {
                        matrix[i][j] = Math.min(Math.min(matrix[i-1][j],matrix[i][j-1]),matrix[i-1][j-1]) + 1;
                    }
                }
            }
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                squares += matrix[i][j];
            }
        }
        return squares;                               
    }
}
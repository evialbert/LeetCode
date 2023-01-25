class Solution
{
public:
    
    bool isValidSudoku(vector<vector<char> > &board)
    {
		//Hashmap for checking repeated number(from 1 to 9) in each row (9 rows), column (9 cols) and grid (9 grids)
        int row[9][9] = {0}, col[9][9] = {0}, grid_3x3[9][9] = {0}; 
        
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
                if(board[i][j] != '.')
                {
                    int num = board[i][j] - '1', k = i/3*3+j/3; //k for finding grid index from 0 to 8
                    if(row[i][num] || col[j][num] || grid_3x3[k][num])
                        return false;
                    row[i][num] = col[j][num] = grid_3x3[k][num] = 1;
                }
        
        return true;
    }
};
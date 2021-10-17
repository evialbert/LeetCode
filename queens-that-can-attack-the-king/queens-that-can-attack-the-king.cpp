class Solution {
public:
    vector<vector<int>>  res;
    
    void checkForQueen(int row,int col,int rowChange,int colChange,vector<vector<char>>& chess)
    {
        if(row < 0 || col < 0 || row == 8 || col == 8)
        {
            return;
        }
        
        if(chess[row][col] == 'Q')
        {
            vector<int> add;
            add.push_back(row);
            add.push_back(col);
            res.push_back(add);
            return;
        }else{
            checkForQueen(row+rowChange,col+colChange,rowChange,colChange,chess);
        }
    }
    
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<char>> chess(8,vector<char> (8,'.'));
        chess[king[0]][king[1]] = 'K';
        for(int i=0;i<queens.size();i++)
        {
            chess[queens[i][0]][queens[i][1]] = 'Q';
        }
        
        checkForQueen(king[0],king[1],-1,0,chess);
        checkForQueen(king[0],king[1],1,0,chess);
        checkForQueen(king[0],king[1],-1,-1,chess);
        checkForQueen(king[0],king[1],-1,1,chess);
        checkForQueen(king[0],king[1],1,-1,chess);
        checkForQueen(king[0],king[1],1,1,chess);
        checkForQueen(king[0],king[1],0,-1,chess);
        checkForQueen(king[0],king[1],0,1,chess);
        
        return res;
    }
};
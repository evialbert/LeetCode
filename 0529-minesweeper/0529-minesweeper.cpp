class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>& vis){
        vis[i][j]=1;
        int m=board.size(),n=board[0].size();
        int count=0;
        for(int r=-1;r<2;r++){
            for(int c=-1;c<2;c++){
                if(i+r>=0&&i+r<m&&j+c>=0&&j+c<n&&board[i+r][j+c]=='M'){
                    count++;
                }
            }
        }
        if(count){
            board[i][j]=(count)+'0';
        }
        else{
            board[i][j]='B';
         for(int r=-1;r<2;r++){
            for(int c=-1;c<2;c++){
                if(i+r>=0&&i+r<m&&j+c>=0&&j+c<n&&vis[i+r][j+c]==0&&board[i+r][j+c]=='E'){
                    dfs(i+r,j+c,board,vis);            
                }
            }
        }   
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        if(board[click[0]][click[1]]=='M'){
            board[click[0]][click[1]]='X';
            return board;
        }
        dfs(click[0],click[1],board,vis);
        return board;
    }
};
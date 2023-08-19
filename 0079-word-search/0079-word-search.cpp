class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        int index = 0;
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == word[index])
                {
                    if(search(i, j, index, board, word))
                        return true;
                }
            }
        }
        
        return false;
    }
    
    bool search(int i, int j, int index, vector<vector<char>>& board, string& word)
    {
        int m = board.size(), n = board[0].size();
        
        if(index == word.size()) return true;
        if(i < 0 or j < 0 or i >= m or j >= n) return false;
        
        bool all = false;
        if(word[index] == board[i][j])
        {
            char temp = word[index];
            board[i][j] = '#';
            all = search(i+1, j, index+1, board, word) or search(i-1, j, index+1, board, word) or 
                search(i, j+1, index+1, board, word) or search(i, j-1, index+1, board, word);
            
            board[i][j] = temp;
        }
        
        return all;
    }
    
};
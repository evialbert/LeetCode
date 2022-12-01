class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        vector<int>d_col{-1, 0, 1, 0}; //left, top, right, below
        vector<int>d_row{0, -1, 0, 1};
        
        for(int i = 0; i < mat.size(); i++)  //Add all cells with 0 to q
            for(int ii = 0; ii < mat[0].size(); ii++)
            {
                if(mat[i][ii] == 0)
                {
                    q.push({i, ii});
                    mat[i][ii] = 0;
                }
            else
                mat[i][ii] = INT_MAX;
            }
        
        while(!q.empty())
        {
            auto cell = q.front(); q.pop();
            auto val = mat[cell.first][cell.second];
            for(int i = 0; i < 4; i++)
            {
                int c = cell.first+d_col[i], r = cell.second+d_row[i];
                if(!isValid(mat, c, r) || mat[c][r] <= val + 1 )
                    continue;  
                mat[c][r] = mat[cell.first][cell.second] + 1;
                q.push({c, r});
            }
        }
                return mat;
    }

    bool isValid(const vector<vector<int>>& mat, int c, int r)
    {
        if(c < 0 || r < 0 || c >= mat.size() || r >= mat[0].size())
            return false;
        return true;
    }
};
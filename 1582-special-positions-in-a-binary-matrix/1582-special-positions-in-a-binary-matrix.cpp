class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m =mat.size();
        int n = mat[0].size();
        vector<int>Row(m,0);
        vector<int>Col(n,0);
        for(int row =0;row<m;row++)
        {
            for(int col =0;col<n;col++)
            {
                if(mat[row][col]==1)
                {
                    Row[row]++;
                    Col[col]++;

                }
            }
        }
        int ans=0;
        for(int row =0;row<m;row++)
        {
            for(int col =0;col<n;col++)
            {
                if(mat[row][col]==1 && Row[row]==1 && Col[col]==1)
                {
                     
                    ans++;
                }
            }
        }
        return ans;
    }
};
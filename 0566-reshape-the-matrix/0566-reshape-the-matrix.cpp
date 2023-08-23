class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size(), n = mat[0].size(), t = m*n;
        if(r*c != t)
            return mat;
        vector<vector<int>> ans(r, vector<int>(c));
        for(int i=0; i<t; i++){
            ans[i/c][i%c] = mat[i/n][i%n];
        }
        return ans;
    }
};
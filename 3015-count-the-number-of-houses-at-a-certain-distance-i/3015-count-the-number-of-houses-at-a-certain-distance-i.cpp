class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> ans(n);
        vector<vector<int>> mat(n, vector<int>(n, 1e8));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(j == i + 1)
                    mat[i][j] = 1, mat[j][i] = 1;
            }
        }
        mat[x - 1][y - 1] = 1;
        mat[y - 1][x - 1] = 1;
        
        for(int k = 0 ; k < n ; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(i != j && mat[i][k] + mat[k][j] < mat[i][j])
                        mat[i][j] = mat[i][k] + mat[k][j];
                }
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i != j)
                    ans[mat[i][j] - 1]++;
            }
        }
        return ans;
    }
};
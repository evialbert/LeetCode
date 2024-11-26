class Solution {
public:
    // we can combine upper, lower into same matrix for less memory usage
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int cen = 0, n = fruits.size();
//for first child
        for(int i = 0; i < n; i++){
            cen += fruits[i][i];
        }
        vector<vector<int>> upper(n + 1, vector<int>(n + 1, -1)), lower(n + 1, vector<int>(n + 1, -1));
        upper[0][n - 1] = fruits[0][n - 1];
        for(int i = 1; i < n; i++){
            for(int j = n - 1; j >= i + 1; j--){
                int m = max({upper[i - 1][j - 1], upper[i - 1][j + 1], upper[i - 1][j]});
                // if m = -1 it means any of previous cells is not visited so we wont update it
                if(m != -1)
                upper[i][j] =  m + fruits[i][j];
            }
        }
        lower[n - 1][0] = fruits[n - 1][0];
        for(int j = 1; j < n; j++){
            for(int i = n - 1; i >= j + 1; i--){
                int m = max({lower[i + 1][j - 1], lower[i][j - 1], lower[i - 1][j - 1]});
                // if m = -1 it means any of previous cells is not visited so we wont update it
                if(m != -1){
                lower[i][j] = m + fruits[i][j];
                }
            }
        }
        int i = n - 1, j = n - 1;
        lower[i][j] = max({lower[i + 1][j - 1], lower[i][j - 1], lower[i - 1][j - 1]});
        upper[i][j] = max({upper[i - 1][j - 1], upper[i - 1][j + 1], upper[i - 1][j]});
        return cen + lower[n - 1][n - 1] + upper[n - 1][n - 1];

    }
};
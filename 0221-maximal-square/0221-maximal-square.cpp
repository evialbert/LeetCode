class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n  = matrix.size(), m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
         for(int i=0; i<m; i++){
            dp[0][i] = matrix[0][i] - '0';
        }
        for(int j = 0; j<n; j++){
            dp[j][0] = matrix[j][0] - '0' ;
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j]=='0'){dp[i][j] = 0;}
                else{
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))  + 1;
            }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(dp[i][j]!=1 and dp[i][j]!=0){
                    int area = dp[i][j]*dp[i][j];
                    ans = max(area, ans);
                }else{
                    int area = dp[i][j];
                    ans = max(area, ans);
                }
            }
        }
        return ans;
    }
};
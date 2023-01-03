class Solution {
public:
    int editDistance(string& word1, string& word2, int m, int n, vector<vector<int>>& dp){
        if(m == 0) return dp[m][n] = n;
        if(n == 0) return dp[m][n] = m;
        if(dp[m][n] != -1)
            return dp[m][n];
        if(word1[m-1] == word2[n-1]) 
            return dp[m][n] = editDistance(word1, word2, m-1, n-1, dp);
        else{
            int insert = editDistance(word1, word2, m, n-1, dp);
            int Delete = editDistance(word1, word2, m-1, n, dp);
            int replace = editDistance(word1, word2, m-1, n-1, dp);
            
            return dp[m][n] = 1 + min({insert, Delete, replace});
        }
    }
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return editDistance(word1, word2, m, n, dp);
    }
};
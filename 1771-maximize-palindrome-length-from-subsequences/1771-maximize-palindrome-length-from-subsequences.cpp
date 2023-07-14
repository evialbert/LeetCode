class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string word = word1 + word2;
        int n = word.length();
        int m = word1.length();
        
        int **dp = new int*[n];
        for(int i = 0; i < n; i++)
            dp[i] = new int[n];
        
        int ans = 0;
        for(int i = 0; i < n; i++) 
            dp[i][i] = 1;
        for(int i = 0; i < n-1; i++) {
            if(word[i] == word[i+1])
                dp[i][i+1] = 2;
            else 
                dp[i][i+1] = 1;
            if(i == m-1)
                ans = dp[i][i+1] == 2 ? 2 : 0;
        }
        
        for(int l = 3; l <= n; l++) {
            for(int i = 0; i < n-l+1; i++) {
                int j = i + l - 1;
                if(word[i] == word[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                    if(i < m && j >= m)
                        ans = max(ans, dp[i][j]);
                }
                else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return ans;
    }
};
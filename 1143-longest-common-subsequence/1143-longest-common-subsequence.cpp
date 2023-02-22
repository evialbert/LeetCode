class Solution {
public:

    // declare a dp
    
    int dp[1005][1005];
    
    int helper(string& str1, string& str2, int i1, int i2, int n1, int n2)
    {
        // base case, if one of the string is empty
        
        if(i1 == n1 || i2 == n2)
            return 0;
        
        // if already calculated
        
        if(dp[i1][i2] != -1)
            return dp[i1][i2];
        
        // if characters are matching
        
        if(str1[i1] == str2[i2])  
            return dp[i1][i2] = 1 + helper(str1, str2, i1 + 1, i2 + 1, n1, n2);
        
        // if characters are not matching
        
        else
        {
            return dp[i1][i2] = max(helper(str1, str2, i1 + 1, i2, n1, n2), helper(str1, str2, i1, i2 + 1, n1, n2));
        }
    }
    
    int longestCommonSubsequence(string str1, string str2) {
        
        int n1 = str1.size();
        
        int n2 = str2.size();
		
		// initialize dp
        
        memset(dp, -1, sizeof(dp));
        
        return helper(str1, str2, 0, 0, n1, n2);
    }
};
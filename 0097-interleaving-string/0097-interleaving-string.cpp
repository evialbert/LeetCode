class Solution {
private:
    bool solver(int i, int j, string& s1, string& s2, string& s3, int dp[][105]){
        if(!(i+j)) return true;
        if(dp[i][j] != -1) return false;
        if(i && s1[i-1] == s3[i+j-1] && solver(i-1,j,s1,s2,s3,dp)) return dp[i][j] = true;

        if(j && s2[j-1] == s3[i+j-1]) return dp[i][j] = solver(i,j-1,s1,s2,s3,dp);

        return dp[i][j] = false;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        int dp[105][105];
        memset(dp,-1,sizeof(dp));
        return solver(s1.size(),s2.size(),s1,s2,s3,dp);
    }
};
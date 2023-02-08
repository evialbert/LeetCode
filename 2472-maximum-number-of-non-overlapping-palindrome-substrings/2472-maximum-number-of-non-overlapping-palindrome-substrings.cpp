class Solution {
public:
    int dp[2001][2001];
    bool isPal(string &s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    int solve(int i,int j,string &s,int k){
        if(j>=s.size() || i>=s.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(isPal(s,i,j)){
            return dp[i][j]=max(solve(i,j+1,s,k),max(solve(j+1,j+k,s,k)+1,solve(i+1,j+1,s,k)));
        }
        return dp[i][j]=max(solve(i+1,j+1,s,k),solve(i,j+1,s,k));
    }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        if(k==1)return n;
        memset(dp,-1,sizeof(dp));
        return solve(0,k-1,s,k);
    }
};
class Solution {
public:
    int dp[4][1001][2001];
    int solve(int p,int i,int c,string &s){
        if(i==s.size())return c>0;
        if(dp[p+1][i][c+1000]!=-1)return dp[p+1][i][c+1000];
        long long ans=0;
        if(p!=0){
            if(s[i]=='E')ans+=solve(0,i+1,c,s);
            else if(s[i]=='F')ans+=solve(0,i+1,c-1,s);
            else ans+=solve(0,i+1,c+1,s);
        }
        if(p!=1){
            if(s[i]=='E')ans+=solve(1,i+1,c+1,s);
            else if(s[i]=='F')ans+=solve(1,i+1,c,s);
            else ans+=solve(1,i+1,c-1,s);
        }
        if(p!=2){
            if(s[i]=='E')ans+=solve(2,i+1,c-1,s);
            else if(s[i]=='F')ans+=solve(2,i+1,c+1,s);
            else ans+=solve(2,i+1,c,s);
        }
        return dp[p+1][i][c+1000]=ans%1000000007;
    }
    int countWinningSequences(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(-1,0,0,s);
    }
};
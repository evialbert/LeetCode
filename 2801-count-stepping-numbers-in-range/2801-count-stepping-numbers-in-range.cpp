class Solution 
{
    int dp[100][2][2][101];
    int f(int i,int ll,int rl,int p,string &low,string& high)
    {
        if(i==low.size()) return 1;
        if(dp[i][ll][rl][1+p]!=-1) return dp[i][ll][rl][1+p];

        int l = ll ? low[i]-'0' : 0;
        int h = rl ? high[i]-'0' : 9;
        int cnt = 0;

        for(int k=l;k<=h;k++)
        {
            if(p==-1 || abs(k-p)==1) cnt =  (cnt + f(i+1,k==l && ll,k==h && rl,(p==-1 && k==0) ? p : k,low,high))%1000000007;
        }
        return dp[i][ll][rl][1+p] = cnt;
    }
public:
    int countSteppingNumbers(string low, string high) 
    {
        memset(dp,-1,sizeof(dp));
        low = string(high.size()-low.size(),'0')+low;
        return f(0,1,1,-1,low,high);
    }
};
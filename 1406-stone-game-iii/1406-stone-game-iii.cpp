class Solution {
public:
    int f(int p,int i,vector<vector<int>>&dp,vector<int>& piles)
    {
        int n=piles.size();
        if(i==n)
        {
            return 0;
        }
        if(dp[p][i]!=-1)
        return dp[p][i];
        int res=p==1?INT_MAX:INT_MIN,s=0;
        for(int x=1;x<=min(3,n-i);x++)
        {
            s+=piles[i+x-1];
            if(p==0)
            {
                res=max(res,s+f(1,i+x,dp,piles));
            }
            else
            {
                res=min(res,f(0,i+x,dp,piles));
            }
        }
        return dp[p][i]=res;
    }
    string stoneGameIII(vector<int>& piles) 
    {
        int n=piles.size();
        vector<vector<int>>dp(2,vector<int>(n+1,-1));
        long long a=f(0,0,dp,piles);
        
        long long t=0;
        for(int i:piles)
        {
            t+=i;
        }
        cout<<a<<" "<<t<<endl;
        if((t-a)==a)
            return "Tie";
        else if((t-a)>a)
            return "Bob";
        else
            return "Alice";
             
    }
};
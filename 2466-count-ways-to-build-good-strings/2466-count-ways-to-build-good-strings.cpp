class Solution {
    int mod = 1e9+7;
    vector<int> dp;
    long ans = 0;
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        dp = vector(high+1,-1);
        for(int i=low;i<=high;i++){
           ans= (ans+dfs(high,zero,one,i))%mod;
        }
        return ans;
    }

    long dfs(int high,int zero,int one,int size){
        if(size<0) return 0;
        if(size==0) return 1;
        if(dp[size]!=-1) return dp[size];
        int x = dfs(high,zero,one,size-zero);
        int y = dfs(high,zero,one,size-one);
        return  dp[size] = (x+y)%mod;
    }
    
};
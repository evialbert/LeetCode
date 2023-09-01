class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int index=i/2;
            
            if(i%2==0){
                dp[i]=dp[index];
            }
            else{
                dp[i]=1+dp[index];
            }
        }
        return dp;
    }
};
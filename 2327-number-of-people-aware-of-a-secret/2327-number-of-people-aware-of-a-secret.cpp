class Solution {
public:
   int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod = 1e9+7;
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 1;i<n;i++){
            for(int j = max(0,i-forget+1);j+delay<=i;j++){
                dp[i]+=dp[j];
                if (dp[i] >= mod) {
                    dp[i] -= mod;
                }
            }
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            if(i+forget>=n) ans += dp[i];
            ans %= mod;
        }
        return ans;
    }
};
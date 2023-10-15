class Solution {
public:
    int mod = 1e9+7;
    int dp[500+3][250+3];

    int solve(int current, int steps, int size){
        if(steps == 0) return dp[steps][current] = current == 0 ? 1 : 0;

        if(dp[steps][current] != -1) return dp[steps][current];

        int ways = 0;
        for(int i = -1 ; i <= 1 ; i++){
            int next = current + i;

            if(next >= steps) continue;

            if(next >= 0 && next < size )
            {   
                ways += solve(next,steps-1,size);
                ways %= mod;   
            }
        }

        return dp[steps][current] = ways;
    }

    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        return solve(0,steps,arrLen);
    }
};
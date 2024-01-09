class Solution {
public:
    
    int dp[100001];
    
    int f(int x, int y){
        if(x < 0) return 1e9;
        if(x <= y) return y - x;
        if(dp[x - y] != -1) return dp[x - y];
        int ans = 1e9;
        ans = min(ans, 1 + (x + 10)/11*11 - x + f((x + 10)/11, y));
        ans = min(ans, 1 + (x + 4)/5*5 - x + f((x + 4)/5, y));
        ans = min(ans, 1 + f(x - 1, y));
        return dp[x - y] = ans;
    }
    
    int minimumOperationsToMakeEqual(int x, int y) {
        memset(dp, -1, sizeof dp);
        return f(x, y);
    }
};
class Solution {
public:
    int topDown(int i, int x, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (x == 0)
            return 1;

        if (dp[i][x] != -1)
            return dp[i][x];

        if (i == 0)
        {
            if (x % coins[0] != 0)
                return dp[0][x] = 0;

            return dp[0][x] = 1;
        }

        int picked = 0;
        
        int coin = coins[i];

        if (x >= coin)
            picked = topDown(i, x - coin, coins, dp);

        int notPicked = topDown(i - 1, x, coins, dp);

        return dp[i][x] = picked + notPicked;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        if (amount == 0)
            return 1;

        if (n == 1)
            return (amount % coins[0] == 0) ? 1 : 0;

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return topDown(n - 1, amount, coins, dp);
    }
};
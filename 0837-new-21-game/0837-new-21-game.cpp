class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
    if (k == 0 || n >= k + maxPts)
        return 1.0;

    vector<double> dp(n + 1, 0.0);
    dp[0] = 1.0;

    double probability = 0.0;
    double sumProbabilities = 1.0;

    for (int i = 1; i <= n; i++) {
        dp[i] = sumProbabilities / maxPts;
        
        if (i < k)
            sumProbabilities += dp[i];
        else
            probability += dp[i];

        if (i - maxPts >= 0)
            sumProbabilities -= dp[i - maxPts];
    }

    return probability;
}

};
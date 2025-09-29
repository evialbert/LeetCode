class Solution {
public:
    int dp[50][50];

    int minTriangulate(vector<int>& values, int i, int j) {
        if (j - i < 2) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];

        int minWeight = INT_MAX;

        for (int k = i + 1; k < j; k++) {
            int currWeight = (values[i] * values[j] * values[k]) +
                             minTriangulate(values, i, k) +
                             minTriangulate(values, k, j);
            
            minWeight = min(minWeight, currWeight);
        }

        return dp[i][j] = minWeight;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        memset(dp, -1, sizeof(dp));
        
        return minTriangulate(values, 0, n - 1);
    }
};
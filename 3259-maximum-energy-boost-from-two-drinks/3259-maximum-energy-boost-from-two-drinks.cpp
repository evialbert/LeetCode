class Solution {
public:
    long long maxEnergyBoost(vector<int>& eDA, vector<int>& eDB) {
        int n = eDA.size();
        if (n == 1) return max(eDA[0], eDB[0]);
        vector<long long> x(n), y(n);
        x[0] = eDA[0], y[0] = eDB[0];
        for (int i = 1; i < n; ++i) {
            x[i] = eDA[i] + max(x[i-1], (i > 1 ? y[i-2] : 0));
            y[i] = eDB[i] + max(y[i-1], (i > 1 ? x[i-2] : 0));
        }
        return max(x[n-1], y[n-1]);
    }
};
class Solution {

public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<int> costs;

        for(int i = 0; i < n - 1; ++i)
        {
            costs.push_back(weights[i] + weights[i + 1]);
        }

        sort(costs.begin(), costs.end());

        long long ans = 0;
        for(int i = 0; i < k - 1; ++i)
        {
            ans += costs[(n - 1) - i - 1];
            ans -= costs[i];
        }

        return ans;
    }
};
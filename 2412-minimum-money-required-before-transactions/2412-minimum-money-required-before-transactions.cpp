class Solution
{
public:
    long long minimumMoney(vector<vector<int>> &transactions)
    {
        long long total_loss = 0;
        int k = 0;
        for (auto &v : transactions)
        {
            k = max(k, min(v[0], v[1])); // v[0] = cost[i], v[1] = cashback[i]
            total_loss += max(v[0] - v[1], 0);
        }
        return total_loss + k;
    }
};
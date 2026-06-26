class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, items[i][1]);
        }

        vector<long long> cnt(n + 1, 0);

        for (int i = 0; i < n; i++) {
            cnt[items[i][0]]++;
        }

        vector<long long> mul(n + 1, 0);

        for (int f = 1; f <= n; f++) {
            for (int m = f; m <= n; m += f) {
                mul[f] += cnt[m];
            }
        }

        map<int, long long> mp;

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            long long d = mul[factor] - 1;

            if (d > 0 && price <= 2 * mini) {
                mp[price] += d;
            }
        }

        long long ans = 0;

        for (auto &it : mp) {
            int price = it.first;
            long long opportunities = it.second;

            long long take = min(opportunities, (long long)budget / price);

            ans += 2 * take;
            budget -= take * price;
        }

        ans += budget / mini;

        return (int)ans;
    }
};
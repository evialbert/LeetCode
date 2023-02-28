class Solution {
public:
    using ll = long long;
    ll maxPower(vector<int>& stations, int r, int k) {
        const int n = size(stations);
        vector<ll> powers(n);
        for (int i = 0; i < n; ++i) {
            powers[max(0, i - r)] += stations[i];
            if (i + r < n - 1) {
                powers[i + r + 1] -= stations[i];
            }
        }
        for (int i = 1; i < n; ++i) {
            powers[i] += powers[i - 1];
        }
        const auto check = [&](ll m) {
            vector<ll> events(n);
            ll stationsAvailable = k;
            ll additionalPower = 0;
            for (int i = 0; i < n; ++i) {
                additionalPower -= events[i];
                if (powers[i] + additionalPower < m) {
                    if (stationsAvailable < m - powers[i] - additionalPower) {
                        return false;
                    }
                    const ll stationsRequired = m - powers[i] - additionalPower;
                    if (i + 2 * r + 1 < n) {
                        events[i + 2 * r + 1] += stationsRequired;
                        additionalPower += stationsRequired;
                        stationsAvailable -= stationsRequired;
                    }
                } 
            }
            return true;
        };
        ll left = 0, right = 1'000'000'000'000'000'000l;
        while (left + 1 < right) {
            const auto m = (left + right) / 2;
            if (check(m)) {
                left = m;
            }
            else {
                right = m;
            }
        }
        return check(right) ? right : left;
    }
};
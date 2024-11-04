class Solution {
public:
    const long long mod = 1e9 + 7;
    vector<long long> freq, fact, ifact;
    long long n, sum;
    vector<vector<vector<long long>>> dp;

    long long binpow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = res * a % m;
            a = a * a % m;
            b >>= 1;
        }
        return res;
    }

    long long count(long long id, long long take, long long cs) {
        if (id == 10) {
            if (take == n / 2 && 2 * cs == sum) {
                return (1LL * fact[n / 2] % mod * fact[(n + 1) / 2] % mod) % mod;
            } else {
                return 0;
            }
        }
        if (dp[id][take][cs] != -1) {
            return dp[id][take][cs];
        }
        long long ways = 0;
        for (long long i = 0; i <= min(freq[id], n / 2 - take); i++) {
            ways = (ways%mod + (1LL * ifact[i] % mod * ifact[freq[id] - i] % mod) % mod * count(id + 1, take + i, cs + i * id) % mod) % mod;
        }
        return dp[id][take][cs] = ways;
    }

    int countBalancedPermutations(string num) {
        n = num.size();
        sum = 0;
        freq.resize(10, 0);
        fact.resize(n + 1, 1);
        ifact.resize(n + 1);

        for (long long i = 0; i < n; i++) {
            freq[num[i] - '0']++;
            sum += (num[i] - '0');
        }

        if (sum % 2) {
            return 0;
        }

        for (long long i = 1; i <= n; i++) {
            fact[i] = (1LL * fact[i - 1] * i) % mod;
        }

        for (long long i = 0; i <= n; i++) {
            ifact[i] = binpow(fact[i], mod - 2, mod) % mod;
        }

        dp.resize(10, vector<vector<long long>>(n + 1, vector<long long>(sum + 1, -1)));
        return count(0, 0, 0) % mod;
    }
};

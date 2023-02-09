class Solution {
public:
    int prime[10];
    long long cache[1001][1001];
    static const int mod = 1e9 + 7;
    long long dp(int i, int k, int& minLength, string& s) {
        if(i == s.size()) {
            return (k == 0 ? 1 : 0);
        }
        long long& ans = cache[i][k];
        if(ans != -1) {
            return ans;
        }
        ans = 0;
        if(prime[s[i] - '0']) {
            for(int j =  i + minLength - 1; j < (int) s.size(); j++) {
                if(prime[s[j] - '0'] == 0 && k - 1 >= 0) {
                    ans += dp(j + 1, k - 1, minLength, s) % mod;
                }
            }
        }
        return ans;
    }
    int beautifulPartitions(string s, int k, int minLength) {
        prime[2] = 1;
        prime[3] = 1;
        prime[5] = 1;
        prime[7] = 1;
        memset(cache, -1, sizeof(cache));
        long long ans = dp(0, k, minLength, s);
        ans %= mod;
        return ans;
    }
};
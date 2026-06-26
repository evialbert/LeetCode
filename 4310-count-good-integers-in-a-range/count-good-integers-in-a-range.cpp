class Solution {
public:
    using ll  = long long;

    ll dp[20][11][2][2];

    ll solve(string& s, int i, int prev, int bound, int k, int start){

        if(i == s.size()) return start;

        if(dp[i][prev][bound][start] != -1)
            return dp[i][prev][bound][start];

        int ub = (bound == 1) ? s[i] - '0' : 9;

        ll ans = 0;

        for(int digit = 0; digit <= ub; digit++){

            if(start == 1 && abs(digit - prev) > k)
                continue;

            ans += solve(
                s,
                i + 1,
                digit,
                bound && (ub == digit),
                k,
                start || (digit != 0)
            );
        }

        return dp[i][prev][bound][start] = ans;
    }

    long long goodIntegers(long long l, long long r, int k) {

        string s = to_string(l - 1);

        memset(dp, -1, sizeof(dp));
        ll left = solve(s, 0, s[0] - '0', 1, k, 0);

        s = to_string(r);

        memset(dp, -1, sizeof(dp));
        ll right = solve(s, 0, s[0] - '0', 1, k, 0);

        return right - left;
    }
};
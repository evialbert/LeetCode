
class Solution {
public:
    typedef long long ll;
    const ll INF = 1000000000000000000LL;
    ll helper(int a, int b) {
        __int128 res = 1;
        for (int i = 0; i < b; i++) {
            res *= (a - i);
            if (res > INF) return INF;
        }
        return (ll)res;
    }
    
    ll solve(int odd, int even, int r, int req) {
        if (r == 0) return 1;
        int nodd, neven;
        if (req == 1) {
            nodd = (r + 1) / 2;
            neven = r / 2;
        } else {
            neven = (r + 1) / 2;
            nodd = r / 2;
        }
        if (odd < nodd || even < neven) return 0;
        ll oddways = helper(odd, nodd);
        ll evenways = helper(even, neven);
        ll total = oddways;
        if (evenways == 0 || total > INF / evenways) total = INF; 
        else total *= evenways;
        return total;
    }
    
    vector<int> permute(int n, long long k) {
        vector<int> ans;
        bool first = false;
        vector<bool> used(n + 1, false);
        int odd = (n + 1) / 2, even = n / 2, last;
        for (int i = 1; i <= n; i++) {
            if (used[i]) continue;
            int odd2 = odd, even2 = even;
            int cp = i & 1;
            int next = (cp == 1 ? 0 : 1);
            if (cp == 1) odd2--; else even2--;
            int r = n - 1;
            ll cnt = solve(odd2, even2, r, next);
            if (k > cnt) k -= cnt; 
            else {
                ans.push_back(i);
                used[i] = true;
                odd = odd2; even = even2;
                last = cp;
                first = true;
                break;
            }
        }
        if (!first) return {};
        for (int z = 1; z < n; z++) {
            bool taken = false;
            for (int j = 1; j <= n; j++) {
                if (!used[j] && ((j & 1) != last)) {
                    int odd2 = odd, even2 = even;
                    int cp = j & 1;
                    if (cp == 1) odd2--; else even2--;
                    int r = n - (z + 1);
                    int next = (cp == 1 ? 0 : 1);
                    ll cnt2 = solve(odd2, even2, r, next);
                    if (k > cnt2) k -= cnt2; else {
                        ans.push_back(j);
                        used[j] = true;
                        odd = odd2; even = even2;
                        last = cp;
                        taken = true;
                        break;
                    }
                }
            }
            if (!taken) return {};
        }
        return ans;
    }
};
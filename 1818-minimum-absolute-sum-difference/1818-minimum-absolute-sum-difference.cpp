class Solution {
public:
    using ll = long long;
    int minAbsoluteSumDiff(vector<int>& A, vector<int>& B) {
        vector<int> AA(A);
        sort(begin(AA), end(AA));
        
        ll res = 0, N = A.size(), mod = 1e9+7, ans = 0;
        for(int i = 0; i < N; i++) res = (res + abs(A[i]-B[i]));

        ans = res;
        for(int i = 0; i < N; i++) {
            ll v = abs(A[i]-B[i]);
            if(!v) continue;
            auto it = lower_bound(begin(AA), end(AA), B[i]);
            if(it != begin(AA)) ans = min(ans, res-max(0ll, v- abs(*prev(it)-B[i])));
            if(it != end(AA)) ans = min(ans, res-max(0ll, v- abs(*(it)-B[i])));
        }
        return ans%mod;
    }
};
class Solution {
public:

    long long score(int l, int r, vector<long long> &pref) {
        return (pref[r] - pref[l]) * (pref[r] - pref[l] + 1) / 2;
    }

    void compute(int l, int r, int optL, int optR, vector<long long> &pref, vector<long long> &prev, vector<long long> &cur) {
        
        if (l > r) return;
        int mid = (l + r) / 2;

        long long best = LLONG_MAX;
        int bestJ = -1;

        int hi = min(optR, mid - 1);
        for (int j = optL; j <= hi; ++j) {
            if (prev[j] == LLONG_MAX) continue;
            long long add = score(j, mid, pref);
            long long cand = prev[j] + add;
            if (cand < best) {
                best = cand;
                bestJ = j;
            }
        }

        cur[mid] = best;

        if (bestJ == -1) return;
        compute(l, mid - 1, optL, bestJ, pref, prev, cur);
        compute(mid + 1, r, bestJ, optR, pref, prev, cur);
        
    }
    
    long long minPartitionScore(vector<int>& nums, int k0) {

        int n = nums.size();
        vector<long long> pref(n + 1);

        for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + nums[i - 1];

        vector<long long> prev(n + 1, LLONG_MAX), cur(n + 1, LLONG_MAX);
        prev[0] = 0;
        
        for (int i = 1; i <= n; ++i) prev[i] = score(0, i, pref);

        for (int k = 2; k <= k0; ++k) {
            fill(cur.begin(), cur.end(), LLONG_MAX);
            compute(k, n, k - 1, n - 1, pref, prev, cur);
            prev.swap(cur);
        }

        return prev[n];
        
    }
};
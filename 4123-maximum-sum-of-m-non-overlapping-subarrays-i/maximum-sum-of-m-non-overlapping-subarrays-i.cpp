class SegTree {
public:
    vector<long long> seg; 
    int n;
    
    SegTree(int size = 0) {
        n = size;
        if (n > 0) seg.assign(4 * n + 1, -1e15);
    }
    
    void insert(int node, int l, int r, int idx, long long val) {
        if (l == r) {
            seg[node] = val;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            insert(2 * node + 1, l, mid, idx, val);
        else
            insert(2 * node + 2, mid + 1, r, idx, val);

        seg[node] = max(seg[2 * node + 1], seg[2 * node + 2]);
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return -1e15; 

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        return max(
            query(2 * node + 1, l, mid, ql, qr),
            query(2 * node + 2, mid + 1, r, ql, qr)
        );
    }
};

class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size(); 
        vector<vector<long long>> dp(n, vector<long long>(m + 1, -1e15));
        
        
        vector<SegTree> a(m + 1, SegTree(n + 1)); 
        vector<long long> pref(n + 1, 0);
        
        for(int i = 1; i <= n; i++) pref[i] = nums[i - 1] + pref[i - 1];
        

        for(int i = 0; i <= n; i++) {
            a[0].insert(0, 0, n, i, 0 - pref[i]);
        }

        for(int i = 0; i < n; i++) {
            for(int p = 1; p <= m; p++) {
               
                long long curr_pref = pref[i + 1]; 
                
                long long prev_dp = (i == 0) ? -1e15 : dp[i - 1][p];
                
               
                long long q_val = (i + 1 - l < 0) ? -1e15 : a[p - 1].query(0, 0, n, max(0, i + 1 - r), i + 1 - l);
                
                dp[i][p] = max(curr_pref + q_val, prev_dp);
                
                a[p].insert(0, 0, n, i + 1, dp[i][p] - curr_pref);
            }
        }
        
        long long ans = -1e15;
        for(int i = 1; i <= m; i++) ans = max(ans, dp[n - 1][i]);
        return ans;
    }
};
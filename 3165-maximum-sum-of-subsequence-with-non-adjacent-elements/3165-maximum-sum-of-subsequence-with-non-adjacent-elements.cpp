class Solution {
public:
    const int mod = 1e9 + 7;
    const int inf = -2e9;
    const static int N = 5e4 + 5;
    long long seg[4 * N][2][2];
    

    void upd(int ind) {
        seg[ind][1][1] = max({seg[2 * ind + 1][1][0] + seg[2 * ind + 2][1][1], seg[2 * ind + 1][1][0] + seg[2 * ind + 2][0][1], seg[2 * ind + 1][1][1] + seg[2 * ind + 2][0][1]});
        seg[ind][1][0] = max({seg[2 * ind + 1][1][0] + seg[2 * ind + 2][1][0], seg[2 * ind + 1][1][0] + seg[2 * ind + 2][0][0], seg[2 * ind + 1][1][1] + seg[2 * ind + 2][0][0]});
        seg[ind][0][1] = max({seg[2 * ind + 1][0][1] + seg[2 * ind + 2][0][1], seg[2 * ind + 1][0][0] + seg[2 * ind + 2][1][1], seg[2 * ind + 1][0][0] + seg[2 * ind + 2][0][1]});
        seg[ind][0][0] = max({seg[2 * ind + 1][0][0] + seg[2 * ind + 2][1][0], seg[2 * ind + 1][0][0] + seg[2 * ind + 2][0][0], seg[2 * ind + 1][0][1] + seg[2 * ind + 2][0][0]});
    }

    void build(int ind, int st, int en, vector<int>& A) {
        if(st == en) {
            seg[ind][1][1] = A[st];
            seg[ind][0][0] = 0;
            seg[ind][0][1] = inf;
            seg[ind][1][0] = inf;
            return;
        }
        int mid = (st + en) >> 1;
        build(2 * ind + 1, st, mid, A);
        build(2 * ind + 2, mid + 1, en, A);
        upd(ind);
    }
    
    void update(int ind, int st, int en, int index, int with) {
        if(st == en) {
            seg[ind][1][1] = with;
            return;
        }
        int mid = (st + en) >> 1;
        if(mid >= index) {
            update(2 * ind + 1, st, mid, index, with);
        }
        else {
            update(2 * ind + 2, mid + 1, en, index, with);
        }
        upd(ind);
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        build(0, 0, n - 1, nums);
        long long ans = 0;
        for(auto q : queries) {
            int index = q[0];
            int with = q[1];
            update(0, 0, n - 1, index, with);
            ans += max({seg[0][0][0], seg[0][0][1], seg[0][1][1], seg[0][1][0]});
            ans %= mod;
        }
        return ans;
    }
};
class Solution {
public:
    int N;
    vector<int> BIT;

    void update(int i, int v) {
        while(i <= N) {
            BIT[i] = max(BIT[i], v);
            i += (i & -i);
        }
    }

    int get(int i) {
        int ans = -1;
        while(i > 0) {
            ans = max(ans, BIT[i]);
            i -= (i & -i);
        }
        return ans;
    }

    int maxFixedPoints(vector<int>& nums) {
        N = (int)nums.size();
        BIT.assign(N+1, 0);
        unordered_map<int, int> rank;
        set<int> s;
        unordered_map<int,vector<int>> mp;
        set<int> uniques;
        for (int i = 0; i < N; ++i) {
            s.insert(i - nums[i]);
            uniques.insert(nums[i]);
            mp[nums[i]].push_back(i);
        }
        int idx = 1;
        for (auto & x:s) {
            rank[x] = idx;
            idx++;
        }
        vector<int> dp(N, 0);
        int ans = 0;
        for (auto & u:uniques) {
            for (auto &x:mp[u]) {
                if (x - u >= 0) {
                    int prev = get(rank[x-u]);
                    dp[x] = max(dp[x], prev + 1);
                    ans = max(ans, dp[x]);
                }
            }
            for (auto &x:mp[u]) {
                if (x - u >= 0) {
                    update(rank[x-u], dp[x]);
                }
            }
        }
        return ans;
    }
};
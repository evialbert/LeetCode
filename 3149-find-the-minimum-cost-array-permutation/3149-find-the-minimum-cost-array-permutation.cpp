class Solution {
public:
    vector<vector<pair<int, string>>> dp;
    pair<int, string> solve(vector<int>& v, int l, int mask, int target) {
        if (mask == target)
            return {abs(l - v[0]), ""};
        if (dp[l][mask].first != -1)
            return dp[l][mask];
        int miniCost = 1e9;
        string s;// string to track the permutation till now
        for (int i = 0; i < v.size(); i++) {
            if ((mask & (1 << i)) == 0) {
                auto b = solve(v, i, mask | (1 << i), target);
                auto c = abs(l - v[i]) + b.first;
                if (c < miniCost) {
                    miniCost = c;
                    s = "";
                    s.push_back((char)('0' + i));
                    s += b.second;
                }
            }
        }
        return dp[l][mask] = {miniCost, s};
    }
    vector<int> findPermutation(vector<int>& nums) {
        int n = nums.size();
        int target = (1 << n) - 1;
        int miniCost = 1e9; //minimum cost 
        string ans;
        dp.assign(n, vector<pair<int, string>>(target, {-1, ""}));
        auto x = solve(nums, 0, 1 << 0, target);
        if (x.first < miniCost) {
            miniCost = x.first;
            ans = "";
            ans.push_back((char)('0'));
            ans += x.second;
        }
        vector<int> ans2;
        for (auto& it : ans)
            ans2.push_back(it - '0');

        return ans2;
    }
};
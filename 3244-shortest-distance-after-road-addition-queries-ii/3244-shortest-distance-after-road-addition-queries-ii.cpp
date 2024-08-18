class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> mp(n, 0), ans;
        for(int i = 0; i < n - 1; i++) mp[i] = i + 1;
        int t = n - 1;
        for(auto &q: queries) {
            if (mp[q[0]] < q[1]) {
                for(int i = mp[q[0]]; i < q[1]; i++) {
                    if (mp[i] != n) {
                        mp[i] = n;
                        t--;
                    }
                }
                mp[q[0]] = q[1];
            }
            ans.push_back(t);
        }
        return ans;
    }
};
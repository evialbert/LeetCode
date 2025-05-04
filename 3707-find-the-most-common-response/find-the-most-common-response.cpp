class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
      
        unordered_map<string, int> mp;

        for (auto& a : responses) {
            unordered_set<string> st(a.begin(), a.end());
            for (auto& s : st) {
                mp[s]++;
            }
        }

        string ans;
        int maxi = 0;

        for (auto& [s, cnt] : mp) {
            if (cnt > maxi || (cnt == maxi && s < ans)) {
                maxi = cnt;
                ans = s;
            }
        }

        return ans;
    }
};
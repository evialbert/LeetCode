class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& Q) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') { if(mp.find(0) == mp.end()) mp[0] = {i, i}; }
            else for(long j = i, v = 0; v <= INT_MAX && j < s.size(); j++) {
                v = (v << 1) + s[j]-'0';
                if(v <= INT_MAX && mp.find(v) == mp.end()) mp[v] = {(int)i, (int)j};
            }
        }
        for(auto q : Q) res.push_back(mp.find(q[0]^q[1]) != mp.end() ? mp[q[0]^q[1]] : vector<int>{-1, -1});
        return res;
    }
};
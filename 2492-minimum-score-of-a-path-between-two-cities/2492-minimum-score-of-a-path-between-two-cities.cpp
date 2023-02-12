class Solution {
public:
    unordered_set<int> s;
    unordered_map<int, vector<int>> mp;
    int minScore(int n, vector<vector<int>>& roads) {
        
        for(auto& r:roads) {
            mp[r[0]].push_back(r[1]);
            mp[r[1]].push_back(r[0]);
        }
        dfs(1);
        //the set s is the connected vertice with 1 and n now.
        
        //find out the minimum edge in connected vertice that including 1 & n;
        int ans = INT_MAX;
        for(auto& r:roads) {
            if(s.find(r[0]) != s.end()) {
                ans = min(ans, r[2]);
            }
        }
        return ans;
        
    }
    void dfs(int root) {
        if(s.find(root) != s.end()) return;
        s.insert(root);
        for(auto&child : mp[root]) {
            dfs(child);
        }
    }
};
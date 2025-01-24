class Solution {
public:
    vector<vector<pair<int,int>>> g;
    vector<int> color;
    int mx = 0, mn = INT_MAX;
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        color = nums;
        g.resize(n);
        for (int i = 0; i < n - 1; i++) {
            g[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            g[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        unordered_map<int, int> mp;
        
        vector<vector<int>> st;
        st.push_back({0, 0});
        dfs(0, mp, -1, 0, st, 0);
        return {mx, mn};
    }
    void dfs(int node, unordered_map<int, int>& pres, int parent, int depth, vector<vector<int>>& st, int index) {
        int dist = st.back()[1] - st[index][1];
        if (dist > mx) {
            mx = dist;
            mn = st.size() - index;
        }
        if (dist == mx && st.size() - index < mn) {
            mn = st.size() - index;
        }
        
        int prev_depth = pres.find(color[node]) != pres.end() ? pres[color[node]] : -1;
        pres[color[node]] = depth;
        for (auto pr : g[node]) {
            if (pr.first == parent) 
                continue;     
            st.push_back({pr.first, st.back()[1] + pr.second});
           
            int newind = pres.find(color[pr.first]) == pres.end() ? -1 : pres[color[pr.first]];
            dfs(pr.first, pres, node, depth + 1 , st, max(index, newind + 1));
            st.pop_back();         
        }
        if (prev_depth < 0) {
            pres.erase(color[node]);
        } else {
            pres[color[node]] = prev_depth;
        }
        return;
    }
};
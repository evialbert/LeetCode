class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        vector<vector<int>> m(parent.size());
        for(int i = 0;i<parent.size();i++) {
            if(parent[i] != -1)
                m[parent[i]].push_back(i);
        }
        vector<int> res(parent.size(), 1);
        vector<int> recentAncestor(26, -1);
        dfs(parent, 0, m, s, recentAncestor,res);
        return res;
    }

    void dfs(vector<int>& parent, int v, vector<vector<int>>& m, string& s, vector<int>& recentAncestor, vector<int>& res) {
        for(int i = 0;i<m[v].size();i++) {
            int k = recentAncestor[s[v]-97];
            recentAncestor[s[v]-97] = v;
            dfs(parent, m[v][i], m, s, recentAncestor, res);
            recentAncestor[s[v]-97] = k;
        }
        if(recentAncestor[s[v]-97] != -1) {
            parent[v] = recentAncestor[s[v] - 97];
            res[recentAncestor[s[v]-97]] += res[v];
        } else {
            if(parent[v] != -1)
                res[parent[v]] += res[v];
        }
    }
};
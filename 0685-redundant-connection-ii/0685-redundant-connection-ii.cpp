class Solution {
public:
    int findparent(int element, vector<int>& parent) {
        if (parent[element] == element) {
            return element;
        } else
            return findparent(parent[element], parent);
    }
    bool checkcycle(vector<vector<int>>& edges_without_blacklist1,
                    vector<int>& parent, vector<int>& blacklist2,
                    vector<int>& rank) {
        for (auto i : edges_without_blacklist1) {
            int u = i[0];
            int v = i[1];
            int pu = findparent(u, parent);
            int pv = findparent(v, parent);
            if (pu == pv) {
                blacklist2.push_back(u);
                blacklist2.push_back(v);
                return true;
            } else if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
                rank[pv]++;
            } else if (rank[pv] < rank[pu]) {
                parent[pv] = pu;
                rank[pu]++;
            } else {
                parent[pu] = pv;
                rank[pv]++;
            }
        }
        return false;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n + 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        vector<int> indegree(n + 1, 0);
        vector<int> blacklist1, blacklist2;
        for (auto i : edges) {
            int u = i[0];
            int v = i[1];
            indegree[v]++;
            if (indegree[v] > 1) {
                blacklist1.push_back(u);
                blacklist1.push_back(v);
            }
        }
        vector<vector<int>> edges_without_blacklist1;
        for (int i = 0; i < n; i++) {
            if (edges[i] == blacklist1) {
                continue;
            } else {
                edges_without_blacklist1.push_back(edges[i]);
            }
        }
        bool cycle =
            checkcycle(edges_without_blacklist1, parent, blacklist2, rank);
        if (blacklist1.empty()) {
            return blacklist2;
        } else if (!blacklist1.empty() && !cycle) {
            return blacklist1;
        }
        else { // 2 parent as well as cycle present
            for (auto& edge : edges) {
            if (edge[1] == blacklist1[1]) {
             return edge; // Return the edge that can be removed to make it a tree
            }
            }
        }
        return {};
    }
};
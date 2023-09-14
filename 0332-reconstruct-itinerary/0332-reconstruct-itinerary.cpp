class Solution {
public:
    unordered_map<string, int> umap;
    vector<string> itin;
    int _n;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> graph;
        _n = tickets.size();
        for (auto& ticket : tickets) {
            graph[ticket[0]].push_back(ticket[1]);
            umap[ticket[0] + ticket[1]]++;
        }
        // sort tickets destinations in lexical order
        for (auto& entity : graph) {
            sort(entity.second.begin(), entity.second.end());
        }
        itin = {"JFK"};
        dfs("JFK", graph);
        return itin;
    }
    bool dfs(string frm, unordered_map<string, vector<string>>& graph) {
        if (itin.size() == _n+1) {
            return true;
        }
        for (auto& str : graph[frm]) {
            string path = frm + str;
            if (umap[path] > 0) {
                umap[path]--;
                itin.push_back(str);
            } else {
                continue;
            }
            if (dfs(str, graph)) return true;
            // backtracking
            umap[path]++; 
            itin.pop_back();
        }
        return false;
    }
};
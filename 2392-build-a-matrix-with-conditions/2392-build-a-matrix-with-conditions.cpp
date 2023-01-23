class TopologicalSort {
public:
    vector<vector<int> > adj;
    int k;
    TopologicalSort(int k, vector<vector<int>>& edges) : adj(k+1) {
        this->k = k;
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[v].push_back(u);
        }
    }
    
    vector<int> getSortingOrder() {
        vector<int> sortingOrder;
        vector<bool> vis(k+1), recStack(k+1);
        for(int i = 1; i <= k; i++) {
            bool isValid = dfs(i, sortingOrder, vis, recStack);
            if(!isValid) {
                return vector<int>();
            }
        }
        return sortingOrder;
    }
    
    bool dfs(int source, vector<int> &sortingOrder, vector<bool> &vis,  vector<bool> &recStack) {
        if(vis[source]) {
            return true;
        }
        vis[source] = true;
        recStack[source] = true;
        for(int i = 0; i < adj[source].size(); i++) {
            int v = adj[source][i];
            if(!vis[v]) {
                if(!dfs(v, sortingOrder, vis, recStack)) {
                    return false;
                }
            } else if(recStack[v]) {
                return false;
            }
        }
        sortingOrder.push_back(source);
        recStack[source] = false;
        return true;
    }
};
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        TopologicalSort rowTopSort(k, rowConditions), colTopSort(k, colConditions);
        vector<int> rowOrder = rowTopSort.getSortingOrder();
        vector<int> colOrder = colTopSort.getSortingOrder();
        if(!rowOrder.size() || !colOrder.size()) {
            return vector<vector<int>>();
        }
        unordered_map<int, int> valueToIndexMap;
        for(int i = 0; i < colOrder.size(); i++) {
            valueToIndexMap[colOrder[i]] = i;
        }
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for(int i = 0; i < rowOrder.size(); i++) {
            int j = valueToIndexMap[rowOrder[i]];
            matrix[i][j] = rowOrder[i];
        }
        return matrix;
    }
};
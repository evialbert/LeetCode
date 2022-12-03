class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, int currNode){
      vis[currNode] = true;
      for(auto &node: graph[currNode]){
        if(!vis[node])
          dfs(graph, vis, node);
      }
    }
    bool canVisitAllRooms(vector<vector<int>>& graph) {
      int n = graph.size();
      vector<bool> vis(n, false);
      dfs(graph, vis, 0);
      for(int i = 0; i < n; i++){
        if(!vis[i]) return false;
      }
      return true;
    }
};
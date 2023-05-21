class Solution {
    void dfs(int curr, vector<int> adjList[], vector<bool> &visited, int &edgeCount, int &vertexCount) {
        if(visited[curr]) return;
        visited[curr] = true;
        vertexCount++;
        edgeCount += adjList[curr].size();
        for(int next: adjList[curr]) {
            dfs(next, adjList, visited, edgeCount, vertexCount);
        }
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> adjList[n];
        vector<bool> visited(n);
        for(vector<int> edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                int edgeCount = 0;
                int vertexCount = 0;
                dfs(i, adjList, visited, edgeCount, vertexCount);
                ans += (edgeCount == vertexCount * (vertexCount - 1));
            }
        }
        return ans;
    }
};
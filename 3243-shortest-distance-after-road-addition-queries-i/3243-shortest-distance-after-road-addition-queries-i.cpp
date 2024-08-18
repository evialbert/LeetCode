class Solution {
public:
    int bfs(int n, vector<vector<int>>& adj) {
        vector<int> dist(n, INT_MAX);
        queue<int> q;
        dist[0] = 0;
        q.push(0);

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it : adj[node]) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
        return dist[n-1] == INT_MAX ? -1 : dist[n-1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i = 0; i < n-1; i++) {
            adj[i].push_back(i+1);
        }

        vector<int> result;
        for(auto it : queries) {
            adj[it[0]].push_back(it[1]);
            int minDis = bfs(n, adj);
            result.push_back(minDis);
        }
        return result;
    }
};
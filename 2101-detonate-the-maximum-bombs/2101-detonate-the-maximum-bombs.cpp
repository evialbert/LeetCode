class Solution {
public:

    void dfs(int node, int &count, vector<vector<int>> &adj, vector<int> &visited){
        visited[node] = true;
        count++;
        for(auto neigh:adj[node]){
            if(!visited[neigh])
                dfs(neigh, count, adj, visited);
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n  = bombs.size();
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
                int xj = bombs[j][0], yj = bombs[j][1];
                if(i != j && (long)ri * ri >= (long)(xi - xj) * (xi - xj) + (long)(yi - yj) * (yi - yj) ){
                    adj[i].push_back(j);
                }
            }
        }

        
        int ans = -1;

        for(int i=0;i<n;i++){
            int count = 0;
            vector<int> visited(n, 0);
            dfs(i, count, adj, visited);
            ans = max(ans, count);
        }


        return ans;
    }
};
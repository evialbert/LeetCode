class Solution {
public:
    int ans = INT_MAX;
    int solve(int ind, vector<vector<int>>& adj, vector<int>& vis){
        queue<pair<int,int>> q;
        q.push({ind,-1});
        int count = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0; i<size; i++){
                int val = q.front().first;
                int par = q.front().second;
                vis[val] = count;
                q.pop();
                for(int i=0; i<adj[val].size(); i++){
                    if(2*count-1 > ans) return INT_MAX;
                    if(vis[adj[val][i]] != 0 && vis[adj[val][i]] == count && par != adj[val][i]){
                        return 2*count-1;
                    }else if(vis[adj[val][i]] != 0 && vis[adj[val][i]] != count && par != adj[val][i]){
                        return 2*count-2;
                    } 
                    else if(vis[adj[val][i]] == 0){
                        q.push({adj[val][i],val});
                    }
                }
            }
            count++;
        }
        return INT_MAX;
    }

    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n); 
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0; i<adj.size(); i++){
            vector<int> vis(n,0);    
            ans = min(ans,solve(i,adj,vis));   
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
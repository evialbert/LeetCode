class Solution {
public:
    long long dfs(int node,vector<vector<int>>& adj,vector<int>& baseTime){
        if(adj[node].empty()){
            return baseTime[node];
        }
        pair<long long,long long>res = {LLONG_MAX,LLONG_MIN};
        for(int i: adj[node]){
            long long t = dfs(i,adj,baseTime);
            res.first = min(res.first,t);
            res.second = max(res.second,t);
        }
        return res.second + baseTime[node] + (res.second - res.first);
        
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        long long res = 0;
        vector<vector<int>>adj(n);
        for(auto &i : edges){
            adj[i[0]].push_back(i[1]);
        }
        return dfs(0,adj,baseTime);
    }
};
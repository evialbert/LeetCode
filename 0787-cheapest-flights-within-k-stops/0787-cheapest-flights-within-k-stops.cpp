class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int stops=p.first;
            int node=p.second.first;
            int cost=p.second.second;
            if(stops>k) continue;
            for(auto it:adj[node]){

                int to=it.first;
                int weight=it.second;
                if(dist[to]>cost+weight){
                    dist[to]=cost+weight;
                    q.push({stops+1,{to,cost+weight}});
                }
            }
        }

        if(dist[dst]==1e9) return -1;
        return dist[dst];

    }
};
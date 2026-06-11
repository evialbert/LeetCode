class Solution {
public:
    vector<long long> dijkstra(int n, int s, vector<vector<pair<int, long long> >>& adj){
        vector<long long> dis(n, 1e18);
        dis[s] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, s});

        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();

            if(d != dis[u]) continue;

            for(auto [v, w]: adj[u]){
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    pq.push({dis[v], v});
                }
            }
        }

        return dis;
    }
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<int> ans;

        vector<vector<pair<int, long long> > > adj1(n), adj2(n);
        for(auto &it: roads){
            int u = it[0], v = it[1], c = it[2], t = it[3];
            adj1[u].push_back({v, c});
            adj1[v].push_back({u, c});

            adj2[u].push_back({v, c * 1LL *t});
            adj2[v].push_back({u, c * 1LL *t});
        }

        for(int i = 0; i < n; i++){
            vector<long long> dis1 = dijkstra(n, i, adj1);
            vector<long long> dis2 = dijkstra(n, i, adj2);
            
            long long cnt = prices[i];
            for(int j = 0; j < n; j++){
                cnt = min(cnt, prices[j] + dis1[j] + dis2[j]);
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};
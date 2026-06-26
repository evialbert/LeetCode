class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector <vector <pair<int,int>>> g(n);
        for (int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            g[u].push_back({v,w});
        }

        vector <vector <int>> dist(n,vector <int> (k+1,1e9));
        vector <vector <int>> vis(n,vector <int> (k+1,0));

        priority_queue <vector <int>> pq;

        vector <int> V = {0,0,1};
        dist[0][1]=0;
        pq.push(V);

        while(!pq.empty()){
            vector <int> V = pq.top();
            pq.pop();
            int node = V[1];
            int k_val = V[2];

            if (vis[node][k_val]==1)continue;
            vis[node][k_val]=1;

            for (auto v:g[node]){
                int next = v.first;
                int w = v.second;
                int new_k = k_val;

                if (labels[node]==labels[next])new_k+=1;
                else new_k=1;

                if (new_k<=k && dist[next][new_k]>dist[node][k_val]+w){
                    dist[next][new_k]=dist[node][k_val]+w;
                    vector <int> temp = {-dist[next][new_k],next,new_k};
                    pq.push(temp);
                }
            }
        }

        int ans = 1e9;

        for (int i=0;i<=k;i++)ans = min(ans,dist[n-1][i]);

        if (ans==1e9)return -1;
        else return ans;
        
    }
};
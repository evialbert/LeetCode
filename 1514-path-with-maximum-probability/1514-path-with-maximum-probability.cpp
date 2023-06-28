class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        using di = pair<double,int>;
        vector<unordered_map<int,double>> g(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0], v = edges[i][1];
            double p = succProb[i];
            g[u][v] = p;
            g[v][u] = p;
        }
        priority_queue<di> pq;
        vector<double> prob(n,-1);
        
        pq.push({1,start});
        while(!pq.empty()){
            auto [sp, u] = pq.top();
            pq.pop();
            if(prob[u] != -1) continue;
            prob[u] = sp;

            for(auto [v,p]: g[u]){
                if(prob[v] != -1) continue;
                pq.push({sp * p,v});
            }
        }
        return max(prob[end],0.0);
    }
};
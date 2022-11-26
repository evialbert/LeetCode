class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size(), res=-1;
        vector<vector<pair<int, int>>> graph(n);
        for(vector<int> e: edges){
            graph[e[0]].push_back({scores[e[1]], e[1]});
            graph[e[1]].push_back({scores[e[0]], e[0]});
        }
        for(int i=0; i<n; i++){
            sort(graph[i].begin(), graph[i].end(), greater<pair<int, int>>());
        }
        for(auto e: edges){
            int b=e[0], c=e[1];
            for(int i=0; i<min(3, (int)graph[b].size()); i++){
                int a = graph[b][i].second;
                if(a==c) continue;
                for(int j=0; j<min(3, (int)graph[c].size()); j++){
                    int d = graph[c][j].second;
                    if(d==b || d==a) continue;
                    res = max(res, scores[a]+scores[b]+scores[c]+scores[d]);
                }
            }
        }
        return res;
    }
};
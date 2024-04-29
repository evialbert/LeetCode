class Solution {
public:
    typedef long long LL;
    void GetShortestPaths(vector<vector<pair<int,int>>>& graph, int n, int st, vector<LL>& dist) {
        dist[st] = 0;
        priority_queue<pair<LL,int>, vector<pair<LL,int>>, greater<pair<LL,int>>> q;
        q.push({0, st});

        while(!q.empty()) {
            auto p = q.top();
            q.pop();
            int u = p.second;
            if(p.first != dist[u]) {
                continue;
            }
            for(auto v : graph[u]) {
                if(dist[u] +  v.second < dist[v.first]) {
                    // s.erase({dist[v.first], v.first});
                    dist[v.first] = dist[u] +  v.second;
                    q.push({dist[v.first], v.first});
                }
            } 
        }
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph;
        graph.resize(n);
        
        for(auto& e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }
        
        
        vector<LL> dist1(n, INT_MAX);
        vector<LL> dist2(n, INT_MAX);
        
        GetShortestPaths(graph, n, 0, dist1);
        GetShortestPaths(graph, n, n-1, dist2);
        
        
        vector<bool> answer(edges.size(), false);
        
        if(dist1[n-1] == INT_MAX) return answer;
        
        int cost = dist1[n-1];
        
        int i=0;
        for(auto& e : edges) {
            if(dist1[e[0]] != INT_MAX && dist2[e[1]] != INT_MAX) {
                int curr = dist1[e[0]] + dist2[e[1]] + e[2];
                if(curr == cost) {
                    answer[i] = true;
                }
            }
            
            
            if(dist2[e[0]] != INT_MAX && dist1[e[1]] != INT_MAX) {
                int curr = dist2[e[0]] + dist1[e[1]]+e[2];
                if(curr == cost) {
                    answer[i] = true;
                }
            }
            
            i++;
        }
        
        return answer;
        
        
    }
};
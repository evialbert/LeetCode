class Solution {
public:
    using vt = vector<int>;
    int minTime(int n, vector<vector<int>>& edges) {
        vector<vector<vt>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back({e[1], e[2], e[3]});
        }
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        priority_queue<vt, vector<vt>, greater<vt>> pq;
        pq.push({0, 0});
        while (!pq.empty()) {
            int u = pq.top()[1], t = pq.top()[0];
            pq.pop();
            for (auto& v : g[u]) {
                if (v[2] < t)
                    continue;
                int t1 = max(t, v[1]) + 1;
                if (dist[v[0]] > t1) {
                    dist[v[0]] = t1;
                    pq.push({t1, v[0]});
                }
            }
        }
        return dist[n - 1] == INT_MAX ? -1 : dist[n - 1];
    }
};
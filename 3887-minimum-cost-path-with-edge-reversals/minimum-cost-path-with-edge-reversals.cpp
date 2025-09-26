class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> eW(n);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            eW[u].push_back({v, w});
            eW[v].push_back({u, 2 * w});
        }
        vector<long long> distances(n, 1e18);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        distances[0] = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto [dist, node] = pq.top(); pq.pop();
            if (dist != distances[node]) continue;
            if (node == n - 1) return dist;
            for (auto [nei, w] : eW[node]) {
                long long nd = dist + w;
                if (nd < distances[nei]) {
                    distances[nei] = nd;
                    pq.push({nd, nei});
                }
            }
        }
        return -1;
    }
};
class Solution {
public:
    bool checkPath(vector<vector<pair<int, int>>>& adj, long long k,
                          vector<bool>& online, int minScore, int n) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            pq;
        vector<long long> nodeCost(n, LLONG_MAX);
        pq.push({0, 0});
        nodeCost[0] = 0;
        while (!pq.empty()) {
            auto [curCost, u] = pq.top();
            pq.pop();
            if (curCost > nodeCost[u])
                continue;
            for (auto& [v, c] : adj[u]) {
                if (c < minScore)
                    continue;
                if (!online[v] && v != n - 1)
                    continue;
                if (nodeCost[v] > curCost + c) {
                    nodeCost[v] = curCost + c;
                    pq.push({nodeCost[v], v});
                }
            }
        }
        return nodeCost[n - 1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> costs;
        set<int> cost;
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            cost.insert(e[2]);
        }
        for(auto &cur : cost){
            costs.push_back(cur);
        }
        int l = 0, r = costs.size() - 1;
        int maxPathScore = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            bool flagCheck = checkPath(adj, k, online, costs[mid], n);
            if (flagCheck) {
                maxPathScore = costs[mid];
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return maxPathScore;
    }
};
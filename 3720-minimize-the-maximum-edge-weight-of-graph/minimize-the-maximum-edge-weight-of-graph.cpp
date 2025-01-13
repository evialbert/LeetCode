class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<pair<int,int>>* revAdj = new vector<pair<int,int>>[n]; // v, wt

        for (auto &e : edges) {
            int u = e[0], v = e[1], wt = e[2];
            revAdj[v].push_back({u, wt});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // minWtToReach, node
        vector<int> vis(n, 0);

        pq.push({0, 0});

        int mxwt = 0;

        while (!pq.empty()) {
            auto [weight, node] = pq.top();
            pq.pop();

            // "weight" is the minimum weight which can be used to reach "node" from 0

            if (vis[node])
                continue;

            vis[node] = 1;
            mxwt = max(mxwt, weight);

            for (auto& [adjNode, wt] : revAdj[node]) {
                if (!vis[adjNode]) {
                    pq.push({wt, adjNode});
                }
            }
        }

        // check if all nodes are visited, n 1's mean all nodes are visited
        int cnt = accumulate(vis.begin(), vis.end(), 0);
        return ((cnt == n) ? mxwt : -1);
    }
};
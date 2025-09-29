class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<tuple<int, int, int>> vals(n * m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vals[i * m + j] = {grid[i][j], i, j};
            }
        }
        sort(vals.rbegin(), vals.rend());
        vector available(k, vals);

        
        using tr = tuple<int, int, int, int>;
        priority_queue<tr, vector<tr>, greater<>> pq;
        vector shortest(n, vector(m, vector<int>(k + 1, INT_MAX/2)));
        pq.push({shortest[0][0][0] = 0, 0, 0, 0});

        while(!pq.empty()) {
            auto [cost, i, j, t] = pq.top();
            pq.pop();
            if(cost > shortest[i][j][t] || (t > 0 && cost >= shortest[i][j][t - 1])) continue;
            if(i == n - 1 && j == m - 1) return cost;

            if(i + 1 < n) {
                int newCost = cost + grid[i + 1][j];
                if(newCost < shortest[i + 1][j][t]) {
                    pq.push({shortest[i + 1][j][t] = newCost, i + 1, j, t});
                }
            }
            
            if(j + 1 < m) {
                int newCost = cost + grid[i][j + 1];
                if(newCost < shortest[i][j + 1][t]) {
                    pq.push({shortest[i][j + 1][t] = newCost, i, j + 1, t});
                }
            }

            if(t < k) {
                while(!available[t].empty() && get<0>(available[t].back()) <= grid[i][j]) {
                    auto& [_, ni, nj] = available[t].back();
                    if(cost < shortest[ni][nj][t + 1]) {
                        pq.push({shortest[ni][nj][t + 1] = cost, ni, nj, t + 1});
                    }
                    available[t].pop_back();
                }
                for(int p = t+1; p < k; p++) {
                    while(!available[p].empty() && get<0>(available[p].back()) <= grid[i][j]) {
                        available[p].pop_back();
                    }
                }
            }
        }
        unreachable();
    }
};
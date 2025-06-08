class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<long long> rf(m, 0);
        vector<long long> rb(m, 0);
        vector<long long> cf(n, 0);
        vector<long long> cb(n, 0);
        vector<unordered_set<int>> rs(m);
        vector<unordered_set<int>> cs(n);
        int mx = 0;

        long long sumf = 0;
        long long sumb = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rs[i].insert(grid[i][j]);
                sumf += grid[i][j];
                sumb += grid[m - 1 - i][j];
            }
            rf[i] = sumf;
            rb[m - 1 - i] = sumb;
        }

        sumf = 0;
        sumb = 0;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                mx = max(mx, grid[i][j]);
                cs[j].insert(grid[i][j]);
                sumf += grid[i][j];
                sumb += grid[i][n - 1 - j];
            }
            cf[j] = sumf;
            cb[n - 1 - j] = sumb;
        }

        for (int i = 0; i < m - 1; i++) {
            if (rf[i] == rb[i + 1])
                return true;
            else {
                long long diff = abs(rf[i] - rb[i + 1]);
                if (diff > mx)
                    continue;
                if (n == 1) {
                    if (rf[i] > rb[i + 1]) {
                        if (grid[0][0] == diff || grid[i][0] == diff)
                            return true;
                    } else {
                        if (grid[i+1][0] == diff || grid[m-1][0] == diff)
                            return true;
                    }
                } else {
                    if (i != 0 && i != m - 2) {
                        if (rf[i] > rb[i + 1]) {
                            for (int j = 0; j <= i; j++) {
                                if (rs[j].find(diff) != rs[j].end())
                                    return true;
                            }
                        } else {
                            for (int j = i + 1; j < m; j++) {
                                if (rs[j].find(diff) != rs[j].end())
                                    return true;
                            }
                        }
                    } else if (i == 0 && i != m - 2) {
                        if (rf[i] > rb[i + 1]) {
                            if (grid[0][0] == diff || grid[0][n - 1] == diff)
                                return true;
                        } else {
                            for (int j = i + 1; j < m; j++) {
                                if (rs[j].find(diff) != rs[j].end())
                                    return true;
                            }
                        }
                    } else if (i == m - 2 && i != 0) {
                        if (rf[i] > rb[i + 1]) {
                            for (int j = 0; j <= i; j++) {
                                if (rs[j].find(diff) != rs[j].end())
                                    return true;
                            }
                        } else {
                            if (grid[m - 1][0] == diff ||
                                grid[m - 1][n - 1] == diff)
                                return true;
                        }
                    } else if (i == 0 && i == m - 2) {
                        if (rf[i] > rb[i + 1]) {
                            if (grid[0][0] == diff || grid[0][n - 1] == diff)
                                return true;
                        } else {
                            if (grid[m - 1][0] == diff ||
                                grid[m - 1][n - 1] == diff)
                                return true;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n - 1; i++) {
            if (cf[i] == cb[i + 1])
                return true;
            else {
                long long diff = abs(cf[i] - cb[i + 1]);
                if (diff > mx)
                    continue;

                if (m == 1) {
                    if (cf[i] > cb[i + 1]) {
                        if (grid[0][0] == diff || grid[0][i] == diff)
                            return true;
                    } else {
                        if (grid[0][i+1] == diff || grid[0][n-1] == diff)
                            return true;
                    }
                } else {
                    if (i != 0 && i != n - 2) {
                        if (cf[i] > cb[i + 1]) {
                            for (int j = 0; j <= i; j++) {
                                if (cs[j].find(diff) != cs[j].end())
                                    return true;
                            }
                        } else {
                            for (int j = i + 1; j < n; j++) {
                                if (cs[j].find(diff) != cs[j].end())
                                    return true;
                            }
                        }
                    } else if (i == 0 && i != n - 2) {
                        if (cf[i] > cb[i + 1]) {
                            if (grid[0][0] == diff || grid[m - 1][0] == diff)
                                return true;
                        } else {
                            for (int j = i + 1; j < n; j++) {
                                if (cs[j].find(diff) != cs[j].end())
                                    return true;
                            }
                        }
                    } else if (i == n - 2 && i != 0) {
                        if (cf[i] > cb[i + 1]) {
                            for (int j = 0; j <= i; j++) {
                                if (cs[j].find(diff) != cs[j].end())
                                    return true;
                            }
                        } else {
                            if (grid[0][n - 1] == diff ||
                                grid[m - 1][n - 1] == diff)
                                return true;
                        }
                    } else if (i == 0 && i == n - 2) {
                        if (cf[i] > cb[i + 1]) {
                            if (grid[0][0] == diff || grid[m - 1][0] == diff)
                                return true;
                        } else {
                            if (grid[0][n - 1] == diff ||
                                grid[m - 1][n - 1] == diff)
                                return true;
                        }
                    }
                }
            }
        }

        return false;
    }
};
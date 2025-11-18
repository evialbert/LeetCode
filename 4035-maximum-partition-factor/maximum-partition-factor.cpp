class Solution {
public:
    bool isBipartite(int i, int c, int d, vector<int>& color,
                     vector<vector<int>>& points) {
        color[i] = c;
        int n = points.size();

        for (int j = 0; j < n; j++) {
            if (j == i || (abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1])) >= d) {
                continue;
            }

            if (color[j] == -1) {

                if (!isBipartite(j, 1 - c, d, color, points)) {
                    return false;
                }
            } else {
                if (color[j] == color[i]) {
                    return false;
                }
            }
        }

        return true;
    }
    bool check(int d, vector<vector<int>>& points) {
        int n = points.size();

        vector<int> color(n, -1);
        

        for (int i = 0; i < n; i++) {

            if (color[i] == -1) {
              
                if (!isBipartite(i, 0, d, color, points)) {
                    return false;
                }
            }
        }

        return true;
    }
    int maxPartitionFactor(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 2) {
            return 0;
        }
        int low = 0;
        int high = 1e9;
        int ans = -1e9;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (check(mid, points)) {
                ans = max(ans, mid);
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int ans = INT_MIN;
        vector<bool> incoming(n, false);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            incoming[v] = true;
        }
        for (int i = 0; i < n; i++) {
            if (!incoming[i] && ans == INT_MIN) {
                ans = i;
            } else if (!incoming[i] && ans != INT_MIN) {
                return -1;
            }
        }
        return ans;
    }
};

//Time Complexity: O(E + N)
//Space Complexity: O(N)
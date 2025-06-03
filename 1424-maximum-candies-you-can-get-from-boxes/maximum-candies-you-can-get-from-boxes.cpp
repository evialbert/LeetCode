class Solution {
public:
    int maxCandies(vector<int>& stt, vector<int>& cd, vector<vector<int>>& keys, vector<vector<int>>& box, vector<int>& ibx) {
        int n = stt.size();  // Total number of boxes
        vector<vector<int>> adj(n);
        vector<bool> vis(n, 0);  // To track visited boxes
        queue<int> q;
        unordered_set<int> nkb;  // Not-yet-unlocked boxes

        // Build graph: box[i] contains list of inner boxes
        for (int i = 0; i < n; i++) {
            for (auto it : box[i])
                adj[i].push_back(it);
        }

        // Process initial boxes
        for (int x : ibx) {
            if (stt[x] == 1) {
                q.push(x);
                vis[x] = 1;
            } else {
                nkb.insert(x);
            }
        }

        int ans = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans += cd[node];  // Collect candies

            // Use all keys found in this box
            for (int it : keys[node]) {
                stt[it] = 1;
                if (nkb.find(it) != nkb.end() && !vis[it]) {
                    q.push(it);
                    vis[it] = 1;
                }
            }

            // Open all contained boxes
            for (int it : box[node]) {
                if (!vis[it]) {
                    if (stt[it] == 1) {
                        q.push(it);
                        vis[it] = 1;
                    } else {
                        nkb.insert(it);
                    }
                }
            }
        }

        return ans;
    }
};
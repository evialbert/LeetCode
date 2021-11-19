//Floyd Warshal 
class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        // normal matrix
        int[][] adj = new int[n][n];
        for (int[] i: adj) {
            Arrays.fill(i, (int)1e8);
        }
        for (int[] i: edges) {
            int u = i[0], v = i[1], w = i[2];
            adj[u][v] = adj[v][u] = w;
        }
        // usinf floydd warshell
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i == j) {
                        adj[i][j] = 0;
                    } else if (i == k || j == k) {
                        continue;
                    } else {
                        adj[i][j] = Math.min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
        int ans = n, idx = 0;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j)
                if (adj[i][j] <= distanceThreshold)
                    ++count;
            if (ans >= count) {
                ans = count;
                idx = i;
            }
        }
        return idx;
    }
}
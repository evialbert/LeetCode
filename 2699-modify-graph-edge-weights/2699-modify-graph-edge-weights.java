class Solution {

    static final int INF = (int) 1e9;

    public int[][] modifiedGraphEdges(int n, int[][] edges, int src, int dst, int t) {
        for (int[] e : edges) {
            if (e[2] == -1) {
                e[2] = INF;
            }
        }
        
        int[][] dist = new int[n][n];
        for (int[] row : dist) Arrays.fill(row, INF);
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (int[] e : edges) {
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }

        // floyd-warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // found
        if (dist[src][dst] == t) {
            return edges;
        }
        // not possible
        if (dist[src][dst] < t) {
            return new int[][] {};
        }

        for (int[] e : edges) {
            if (e[2] == INF) {
                e[2] = 1;
                update(n, dist, e[0], e[1], e[2]);
                update(n, dist, e[1], e[0], e[2]);
                if (dist[src][dst] <= t) {
                    e[2] += t - dist[src][dst];
                    update(n, dist, e[0], e[1], e[2]);
                    update(n, dist, e[1], e[0], e[2]);
                    return edges;
                }
            }
        }
        return new int[][] {};
    }

    void update(int n, int[][] dist, int u, int v, int d) {
        if (dist[u][v] > d) {
            dist[u][v] = d;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][j] > dist[i][u] + dist[u][v] + dist[v][j]) {
                        dist[i][j] = dist[i][u] + dist[u][v] + dist[v][j];
                    }
                }
            }
        }           
    }

}
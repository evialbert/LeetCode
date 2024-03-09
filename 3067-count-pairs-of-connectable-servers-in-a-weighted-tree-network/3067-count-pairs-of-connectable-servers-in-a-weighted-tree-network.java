class Solution {
    public int[] countPairsOfConnectableServers(int[][] edges, int signalSpeed) {
        int n = edges.length + 1;
        List<int[]>[] g = new ArrayList[n];
        for (int i = 0; i < n; ++i) g[i] = new ArrayList();
        for (int[] e : edges) {
            g[e[0]].add(new int[] {e[1], e[2]});
            g[e[1]].add(new int[] {e[0], e[2]});
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            int nodeCnt = 0, pairCnt = 0;
            for (int[] e : g[i]) {
                int cnt = dfs(g, i, e[0], e[1], signalSpeed);
                pairCnt += nodeCnt * cnt;
                nodeCnt += cnt;
            }
            ans[i] = pairCnt;
        }
        return ans;
    }

    private int dfs(List<int[]>[] g, int parent, int current, int w, int signalSpeed) {
        int cnt = 0;
        if (w % signalSpeed == 0) ++cnt;
        for (int[] e : g[current]) {
            if (e[0] != parent) {
                cnt += dfs(g, current, e[0], w + e[1], signalSpeed);
            }
        }
        return cnt;
    }
}
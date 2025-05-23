class Solution {

    int[] depth;
    int[] depth2;
    int[][] parents; // parents in 1, 2, 4, ..., upward steps.
    List<Map<Integer, Integer>> nei;

    void dfs(int p, int cur, int len, int len2) {
        depth[cur] = len;
        depth2[cur] = len2;
        parents[cur][0] = p;
        for(var kv : nei.get(cur).entrySet()) {
            if(kv.getKey() == p) continue;
            dfs(cur, kv.getKey(), len + kv.getValue(), len2 + 1);
        }
    }

    int findp(int i, int j) {
        if(i == j) return i;
        if(depth2[i] < depth2[j]) {
            int t = i;
            i = j;
            j = t;
        }
        int xp = depth2[i] - depth2[j];
        int h;
        while(xp > 0) {
            h = 31 - Integer.numberOfLeadingZeros(xp);
            i = parents[i][h];
            xp &= ~(1 << h);
        }
        if(i == j) return i;
        h = 31 - Integer.numberOfLeadingZeros(depth2[j]);
        while(i != j && h >= 0) {
            if(parents[i][h] != parents[j][h]) {
                i = parents[i][h];
                j = parents[j][h];
            }
            h--;
        }
        return i == j ? i : parents[i][0];
    }

    public int[] minimumWeight(int[][] edges, int[][] queries) {
        int n = edges.length + 1;
        parents = new int[n][32 - Integer.numberOfLeadingZeros(n)];
        nei = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            nei.add(new HashMap<>());
        }
        for(int[] e : edges) {
            nei.get(e[0]).put(e[1], e[2]);
            nei.get(e[1]).put(e[0], e[2]);
        }
        for(int[] p : parents) Arrays.fill(p, -1);
        depth = new int[n];
        depth2 = new int[n];
        dfs(-1, 0, 0, 0);

        for(int len = 1; (1 << len) < n; len++) {
            for(int i = 0; i < n; i++) {
                int curp = parents[i][len-1];
                if(curp >= 0) {
                    parents[i][len] = parents[curp][len - 1];
                }
            }
        }

        int[] res = new int[queries.length];
        int[][] ind = new int[3][4];
        for(int i = 0; i < res.length; i++) {
            ind[0][0] = findp(queries[i][0], queries[i][1]);
            ind[0][1] = queries[i][2]; ind[0][2] = queries[i][0]; ind[0][3] = queries[i][1];

            ind[1][0] = findp(queries[i][1], queries[i][2]);
            ind[1][1] = queries[i][0]; ind[1][2] = queries[i][1]; ind[1][3] = queries[i][2];

            ind[2][0] = findp(queries[i][2], queries[i][0]);
            ind[2][1] = queries[i][1]; ind[2][2] = queries[i][2]; ind[2][3] = queries[i][0];

            ind = Arrays.stream(ind).sorted((a, b)->Integer.compare(depth[b[0]], depth[a[0]])).toArray(int[][]::new);

            res[i] = depth[ind[0][0]] + depth[ind[0][1]] - 2 * depth[findp(ind[0][0], ind[0][1])] + depth[ind[0][2]] + depth[ind[0][3]] - 2 * depth[ind[0][0]];
        }
        return res;
    }
}
class Solution {
    public int maxWeight(int n, int[][] edges, int k, int t) {
        int[][][] dp = new int[n][k + 1][t + 1];
        Map<Integer, List<List<Integer>>> adj = buildAdj(edges);

        initializeDpArray(dp);

        int ans = -1;

        for(int i=0;i<n;i++) {
            ans = Math.max(ans, solve(adj, i, k, t, dp));
        }
        return ans;
    }

    private int solve(Map<Integer, List<List<Integer>>> adj, int src, int k, int target, int[][][] dp) {
        if(k < 0 || target <= 0)
            return Integer.MIN_VALUE;
        if(k == 0)
            return 0;

        if(dp[src][k][target] != -1) {
            return dp[src][k][target];
        }
        int ans = Integer.MIN_VALUE;

        for(List<Integer> neighbour: adj.getOrDefault(src, Collections.emptyList())) {
            if(neighbour.get(1) < target) {
                int tempAns = solve(adj, neighbour.get(0), k - 1, target - neighbour.get(1), dp);

                if(tempAns != Integer.MIN_VALUE) {
                    tempAns += neighbour.get(1);
                    ans = Math.max(ans, tempAns);
                }
            }
        }
        return dp[src][k][target] = ans;
    }

    private Map<Integer, List<List<Integer>>> buildAdj(int[][] edges) {
        Map<Integer, List<List<Integer>>> adj = new HashMap<>();

        for(int[] edge: edges) {
            adj.computeIfAbsent(edge[0], key -> new ArrayList<>())
                .add(Arrays.asList(edge[1], edge[2]));
        }
        return adj;
    }

    private void initializeDpArray(int[][][] dp) {
        for(int[][] firstLayer: dp) {
            for(int[] secondLayer: firstLayer) {
                Arrays.fill(secondLayer, -1);
            }
        }
    }
}
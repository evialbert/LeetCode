class Solution {
    Map<Integer, Set<Integer>> edgeMap = new HashMap<>();
    int ans = 0;

    public int countGoodNodes(int[][] edges) {
        if (edges == null || edges.length == 0)
            return ans;
            
        for (int[] edge : edges) {
            edgeMap.putIfAbsent(edge[0], new HashSet<>());
            edgeMap.putIfAbsent(edge[1], new HashSet<>());
            edgeMap.get(edge[0]).add(edge[1]);
            edgeMap.get(edge[1]).add(edge[0]);
        }

        boolean[] visited = new boolean[edges.length + 1];
        visited[0] = true;
        dfs(0, visited);
        return ans;
    }

    public int dfs(int v, boolean[] visited) {
        List<Integer> temp = new ArrayList<>();

        for (int e : edgeMap.get(v)) {
            if (!visited[e]) {
                visited[e] = true;
                temp.add(dfs(e, visited));
            }
        }
        Set<Integer> uniques = new HashSet<>(temp);
        if (uniques.size() == 1 || temp.size() == 0) {
            ans++;
        }

        return (temp.size() == 0) ? 1 : 1 + temp.stream().mapToInt(i -> i).sum();
    }
}
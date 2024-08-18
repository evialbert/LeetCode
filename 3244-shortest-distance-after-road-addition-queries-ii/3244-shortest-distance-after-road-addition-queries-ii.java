class Solution {
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        Map<Integer, Integer> d = new HashMap<>();
        for (int i = 0; i < n - 1; ++i) {
            d.put(i, i + 1);
        }
        int res[] = new int[queries.length], qi = 0;
        for (int[] q : queries) {
            int i = q[0], j = q[1];
            if (d.containsKey(i) && d.get(i) < j) {
                int v = i;
                while (v < j && d.containsKey(v)) {
                    v = d.remove(v);
                }
                d.put(i, j);
            }
            res[qi++] = d.size();
        }
        return res;
    }
}
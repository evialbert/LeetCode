class Solution {
    public int[] baseUnitConversions(int[][] conversions) {
        int nss = conversions.length + 1;
        List<int[]>[] grh = new ArrayList[nss];
        for (int i = 0; i < nss; i++) grh[i] = new ArrayList<>();
        for (int[] conv : conversions) {
            grh[conv[0]].add(new int[]{conv[1], conv[2]});
        }
        
        int[] rs = new int[nss];
        rs[0] = 1;
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int[] next : grh[u]) {
                int vss = next[0], far = next[1];
                rs[vss] = (int)((1L * rs[u] * far) % Module);
                q.offer(vss);
            }
        }
        
        return rs;
    }
    static final int Module = (int)1e9 + 7;

    
}
class Solution {
    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        int group[] = new int[n];
        int gno = 0;
        group[0] = 0;
        for(int i=1; i<n; i++) {
            if(nums[i]-nums[i-1] > maxDiff) gno++;
            group[i] = gno;
        }
        
        boolean[] res = new boolean[queries.length];
        int i=0;
        for(int[] que: queries) {
            int u = que[0], v = que[1];
            if(group[u] == group[v]) res[i] = true;
            i++;
        }
        return res;
    }
}
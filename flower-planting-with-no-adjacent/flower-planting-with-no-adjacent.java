class Solution {
    public int[] gardenNoAdj(int N, int[][] paths) {
        int[] colors = new int[N]; // just for convience
        
        Set<Integer>[] gardens = new Set[N+1];
        
        for (int i = 1; i<=N; i++)
            gardens[i] = new HashSet();
        
        for (int[] path : paths) {
            gardens[path[0]].add(path[1]);
            gardens[path[1]].add(path[0]);
        }
        
        for (int i=1; i<=N; i++) {
            int[] used = new int[5];
            for (Integer k : gardens[i])
                used[colors[k-1]] = 1;
            
            int color = 1;
            while (used[color]!=0) color++;
            colors[i-1] = color;
        }
        return colors;
    }
}
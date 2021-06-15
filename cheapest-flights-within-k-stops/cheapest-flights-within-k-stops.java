class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
//         Bellman Ford
        
        int[] path = new int[n];
        Arrays.fill(path, Integer.MAX_VALUE);
        path[src] = 0;
        
        for(int i = 0; i<=k; i++){
            int temp[] = path.clone(); // temp array is used so that at kth iteration only node at k
									   // stops away can fill
            for(int j = 0; j<flights.length; j++){
                int u = flights[j][0];
                int v = flights[j][1];
                int wt = flights[j][2];
                
                if(path[u] != Integer.MAX_VALUE){
                    temp[v] = Math.min(temp[v], path[u] + wt);
                }
            }
            path = temp;
        }
        
        return path[dst] == Integer.MAX_VALUE ? -1 : path[dst];
        
    }
}
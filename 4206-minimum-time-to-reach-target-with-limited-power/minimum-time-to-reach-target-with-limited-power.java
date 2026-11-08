class Solution {
    public void dijkstra(List<int[]>[] graph, int src, int pow, int[] cost, long[][] time){
        PriorityQueue<long[]> pq = new PriorityQueue<>((a, b) -> Long.compare(a[1], b[1])); // sort by asc time
        time[src][pow] = 0; // time for this node(src) and pow = 0
        pq.offer(new long[]{src, 0, pow});
        while(!pq.isEmpty()){
            long[] curr = pq.poll();
            int u = (int)curr[0];
            long t = curr[1];
            int p = (int)curr[2];
            
            if(t>time[u][p]) continue; // time already minimized
            if(p<cost[u]) continue; // we can't go beyond power limit

            for(int[] ngbr : graph[u]){
                int v = ngbr[0];
                int vt = ngbr[1];
                int nextP = p-cost[u];
                if(time[v][nextP]>t+vt){ // relax
                    time[v][nextP] = t+vt;
                    pq.offer(new long[]{v, t+vt, p-cost[u]});
                }
            }
        }
    }
    public long[] minTimeMaxPower(int n, int[][] edges, int power, int[] cost, int source, int target) {
        @SuppressWarnings("unchecked")
        List<int[]>[] graph = new ArrayList[n];
        for(int i=0; i<n; i++){
            graph[i] = new ArrayList<>();
        }
        for(int[] e : edges){
            int u = e[0];
            int v = e[1];
            int t = e[2];
            graph[u].add(new int[]{v, t});
        }

        long[][] time = new long[n][power+1];
        for(int i=0; i<n; i++){
            Arrays.fill(time[i], Long.MAX_VALUE);
        }
        dijkstra(graph, source, power, cost, time);

        // Result Building
        long minTime = Long.MAX_VALUE;
        long maxPower = -1;
        for(int p=0; p<=power; p++){
            // get the min time & power
            if(time[target][p]<minTime){
                minTime = time[target][p];
                maxPower = p;
            }else if(time[target][p]==minTime && minTime!=Long.MAX_VALUE){
                maxPower = p;
            }
        }
    
        return minTime==Long.MAX_VALUE? (new long[]{-1, -1}) : (new long[]{minTime, maxPower});
    }
}
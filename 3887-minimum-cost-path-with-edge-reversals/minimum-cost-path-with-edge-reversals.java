class Solution {
    static class Edge {
        int to;
        int weight;
        Edge(int to, int weight) {
            this.to = to;
            this.weight = weight;
        }
    }
    public int minCost(int n, int[][] edges) {
        List<Edge>[] graph = new ArrayList[n];

        for(int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }

        for(int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            graph[u].add(new Edge(v, w));
            graph[v].add(new Edge(u, 2*w));
        }

        int[] dist = new int[n]; //najkraci put do svakog cvora od pocetnog
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0] = 0;

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
        pq.add(new int[]{0, 0});//dodajemo cvor sa distancom do njega
        
        while(!pq.isEmpty()) {
            int[] current = pq.poll();
            int currentNode = current[0];
            int distanceToCurrentNode = current[1];
            //if(currentNode == n - 1) return dist[currentNode];
            if(currentNode == n - 1) return distanceToCurrentNode;
            for(Edge edge : graph[currentNode]) {
                int nextNode = edge.to;
                int weight = edge.weight;
                if(dist[nextNode] > distanceToCurrentNode + weight) {
                    dist[nextNode] = distanceToCurrentNode + weight;
                    pq.add(new int[]{nextNode, dist[nextNode]});
                }
            }
        }
        //return dist[n - 1] == Integer.MAX_VALUE ? -1 : dist[n - 1] ;
        return -1;
    }
}
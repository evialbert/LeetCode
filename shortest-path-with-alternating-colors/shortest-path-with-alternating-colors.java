class Solution {     
    public int[] shortestAlternatingPaths(int n, int[][] red_edges, int[][] blue_edges) {
        List<Integer>[] redGraph = buildGraph(n, red_edges);  // subgraph with red edges only
        List<Integer>[] blueGraph = buildGraph(n, blue_edges);  // subgraph with blue edges only
        boolean[] redVisited = new boolean[n];   // nodes visited by a red edge
        boolean[] blueVisited = new boolean[n];   // nodes visited by a blue edge
        Queue<Integer> redQueue = new LinkedList<Integer>();  // nodes last accessed via a red edge
        Queue<Integer> blueQueue = new LinkedList<Integer>();   // nodes last accessed via a blue edge 
        int[] result = new int[n];
        int distance = 0;
        int redQueueLength;
        int blueQueueLength;
        
        redQueue.offer(0);
        redVisited[0] = true;
        
        blueQueue.offer(0);
        blueVisited[0] = true;
        
        Arrays.fill(result, -1);
        result[0] = 0;
        
        while (!redQueue.isEmpty() || !blueQueue.isEmpty()) {
            distance++;
            redQueueLength = redQueue.size();
            blueQueueLength = blueQueue.size();
            explore(redQueue, blueQueue, blueGraph, blueVisited, result, distance, redQueueLength);
            explore(blueQueue, redQueue, redGraph, redVisited, result, distance, blueQueueLength);
        }
        
        return result;
    }
    
    private List<Integer>[] buildGraph(int n, int[][] edges) {
        List<Integer>[] graph = new ArrayList[n];
        
        for (int[] edge : edges) {
            if (graph[edge[0]] == null) {
                graph[edge[0]] = new ArrayList<Integer>();
            }
            
            graph[edge[0]].add(edge[1]);
        }
        
        return graph;
    }
    
    private void explore(Queue<Integer> queue, Queue<Integer> otherQueue, List<Integer>[] otherGraph, boolean[] otherVisited, int[] result, int distance, int queueLength) {        
        for (int count = 0; count < queueLength; count++) {
            int current = queue.poll();

            if (otherGraph[current] != null) {
                for (int adjacent : otherGraph[current]) {
                    if (!otherVisited[adjacent]) {
                        otherVisited[adjacent] = true;
                        otherQueue.offer(adjacent);

                        if (result[adjacent] == -1) {
                            result[adjacent] = distance;
                        }
                    }
                }
            }
        }
    }
}
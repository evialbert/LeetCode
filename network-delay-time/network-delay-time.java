//Java solution using Dijkstra's and Priority Queue
class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<int[][]>> adjList = new ArrayList<>();

        for(int i=0;i<n;i++){
            adjList.add(new ArrayList<>());
        }
        
        for(int[] arr : times){
            int src= arr[0]-1;
            int dest= arr[1]-1;
            int weight= arr[2];
            adjList.get(src).add(new int[][] {{dest , weight}});
        }
        
        PriorityQueue<Integer> q = new PriorityQueue<>();
        int[] distances = new int[n];
        Arrays.fill(distances,Integer.MAX_VALUE);
        
        q.add(k-1);
        distances[k-1]=0;
        
        while(!q.isEmpty()){
            int curr = q.poll();
            List<int[][]> neighbours = adjList.get(curr);
            for(int[][] pair : neighbours){
                if((distances[curr]+pair[0][1]) < distances[pair[0][0]]){
                    distances[pair[0][0]] = distances[curr]+pair[0][1];
                    q.add(pair[0][0]);
                }
            }
        }

        int max=0;
        for(int i : distances){
            if(i>max){
                max=i;
            }
        }
        if(max==Integer.MAX_VALUE) return -1;
        return max;
        
    }
}
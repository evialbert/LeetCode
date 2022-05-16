class Solution {
    public int minimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
        HashMap<Integer, List<Integer>> graph = new HashMap<>();
        
        for(int i=0; i<source.length; i++)
            graph.put(i, new LinkedList<>());
        
        for(int[] edge: allowedSwaps){
            graph.get(edge[0]).add(edge[1]);
            graph.get(edge[1]).add(edge[0]);
        }
        
        List<List<Integer>> connected_components = new ArrayList<>();
        
        boolean[] visited = new boolean[source.length];
        
        for(int i=0; i<source.length; i++){
            if(!visited[i]){
                List<Integer> l = new ArrayList<>();
                DFS(graph, i, l, visited);
                connected_components.add(new ArrayList<>(l));
            }
        }
        
        int Hamming_Distance = 0;
        
        for(List<Integer> l: connected_components){
            HashMap<Integer, Integer> hm = new HashMap<>();
            
            for(int i=0; i<l.size(); i++){
                int val = source[l.get(i)];
                
                if(hm.containsKey(val))
                    hm.put(val, hm.get(val)+1);
                else
                    hm.put(val, 1);
            }
            
            for(int i=0; i<l.size(); i++){
                int val = target[l.get(i)];
                
                if(!hm.containsKey(val))
                    Hamming_Distance++;
                
                else{
                    hm.put(val, hm.get(val)-1);
                    
                    if(hm.get(val) == 0)
                        hm.remove(val);
                }
            }
        }
        
        return Hamming_Distance;
    }
    
    public void DFS(HashMap<Integer, List<Integer>> graph, int src, List<Integer> l, boolean[] visited){
        visited[src] = true;
        
        l.add(src);
        
        Iterator<Integer> it = graph.get(src).iterator();
        
        while(it.hasNext()){
            int u = it.next();
            if(!visited[u])
                DFS(graph, u, l, visited);
        }
    }
}
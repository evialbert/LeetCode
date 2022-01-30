class Solution {
    
    int[][] edges;
    int n;
    
    public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int _n, int[][] _edges) {
        this.edges = _edges;
        this.n = _n;
        List<Integer> critical = new ArrayList<Integer>();
        List<Integer> nonCritical = new ArrayList<Integer>();
        Map<int[],Integer> graph = new HashMap<int[],Integer>();
        for(int i = 0; i<edges.length;i++)graph.put(edges[i],i);
        Arrays.sort(edges,(a,b)->a[2]-b[2]);
        int minSpanningTree = findMinSpanningTree(0,-1);
        for(int i = 0; i<edges.length;i++){
            int index = graph.get(edges[i]);
            if(findMinSpanningTree(0,i)>minSpanningTree)critical.add(index);
            else if(findMinSpanningTree(i,-1)==minSpanningTree)nonCritical.add(index);
        }
        return List.of(critical,nonCritical);
    }
    
    private int findMinSpanningTree(int start, int skip){
        UnionFind uf = new UnionFind(n);
        int cost = 0;
        if(skip!=0){
           uf.union(edges[start][0],edges[start][1]);
           cost+=edges[start][2]; 
        }
        for(int i =0; i<edges.length;i++){
            if(i==skip)continue;
            int[] edge = edges[i];
            if(uf.find(edge[0])!=uf.find(edge[1])){
                uf.union(edge[0],edge[1]);
                cost+=edge[2];
            }
        }
        return uf.count == n-1 ? cost : Integer.MAX_VALUE;
    }
    
    class UnionFind{
        
        int[] parent;
        int count;
        
        public UnionFind(int n){
            this.parent = new int[n];
            this.count = 0;
            for(int i = 0;i<n;i++)this.parent[i] = i;
        }
        
        public void union(int a, int b){
            this.count++;
            a = find(a);
            b = find(b);
            parent[a] = b;
        }
        
        public int find(int n){
            while(parent[n]!=n){
                n = parent[n];
            }
            return n;
        }
    }
}
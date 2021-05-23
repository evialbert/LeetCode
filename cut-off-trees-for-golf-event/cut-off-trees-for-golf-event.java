class Solution {
    int [] move_X = new int[]{1, -1, 0, 0};
    int [] move_Y = new int[]{0,  0, 1,-1};
    
    class Node implements Comparable<Node>{
        public int val;
        public int row;
        public int col;
        
        public Node(int v, int r, int c){
            this.val = v;
            this.row = r;
            this.col = c;
        }
        
        public int compareTo(Node n){
            if(this.val > n.val)
                return 1;
            else if(this.val < n.val)
                return -1;
            else
                return 0;
        }
    }
    
    public int cutOffTree(List<List<Integer>> forest) {
        //solving using BFS
        //sort the trees according to their height
        List<Node> trees = new ArrayList();
        int n = forest.size();
        int m = forest.get(0).size();
        
        for(int i = 0; i< n;i++)
        {
            for(int j = 0;j<m;j++){
                if(forest.get(i).get(j) > 1)
                    trees.add(new Node(forest.get(i).get(j), i, j));
            }
        }
        //Sort trees according to their height
        Collections.sort(trees);
        
        //Start search from 0, 0  (d is the distance to find a node)
        int ans = 0, d = 0;
        Node source = new Node(0,0,0);
        for(Node tree : trees)
        {           
            d = BFS(forest, source, tree, n , m);
            if(d == -1)
                return -1;
            ans += d; 
            //found the node looking for and the new source will be that node
            source.row = tree.row;
            source.col = tree.col;
        }
        return ans;
    }
    
    boolean isSafe(int i, int j, int n, int m){
        if(i<0 || j<0 || i>n-1 || j>m-1)
            return false;
        return true;
    }
    
    public int BFS(List<List<Integer>> forest, Node source, Node target, int n, int m)
    {
        boolean [][] visited = new boolean[n][m];
        visited[source.row][source.col] = true;
        //store <source, target, distance travelled>
        Queue<int[]> q = new LinkedList();
        q.add(new int[]{source.row, source.col, 0});
        while(!q.isEmpty()){
            int [] curr = q.poll();
            if(curr[0] == target.row && curr[1] == target.col)
                return curr[2];
            //go through the 4 directions
            for(int i=0;i<4;i++){
                int row = curr[0] + move_X[i];
                int col = curr[1] + move_Y[i];
                
                if(isSafe(row, col, n , m)){
                    if(!visited[row][col] && forest.get(row).get(col) > 0)
                    {
                        visited[row][col] = true;
                        q.add(new int[]{row, col, curr[2] + 1});
                    }
                }
            }
        }
        return -1;
    }
    
}
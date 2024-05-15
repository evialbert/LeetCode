class Solution {
    // directions
    int[][] dirArr = new int[][]{{0,1}, {0,-1}, {1,0}, {-1,0}};

    public int maximumSafenessFactor(List<List<Integer>> grid) {
        int m = grid.size();
        int n = grid.get(0).size();
        int[][] mat = new int[m][n];
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                mat[i][j]=grid.get(i).get(j);

        // no path possible
        if(mat[0][0]==1 || mat[m-1][n-1]==1)return 0;

        // pre-populate safety
        int[][] safety = new int[m][n];        
        Queue<int[]> queue = new LinkedList<>();
        
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    queue.add(new int[]{i,j,0});  
                    // since node has thief himself
                    safety[i][j]=0;
                } else safety[i][j]=Integer.MAX_VALUE;                     
            }            
        // bfs to fill safety for all nodes        
        while(!queue.isEmpty()){
            int size = queue.size();
            while(size-->0){
                int[] curr = queue.poll();
                int currx = curr[0];
                int curry = curr[1];
                for(int[] dir:dirArr){
                    int nextx = currx+dir[0];
                    int nexty = curry+dir[1];
                    if(isValid(nextx, nexty, mat) && curr[2]+1 < safety[nextx][nexty]){
                        queue.add(new int[]{nextx, nexty, curr[2]+1});
                        safety[nextx][nexty]=curr[2]+1;
                    }
                }                
            }
        }
        // bfs to find safest path
        Queue<int[]> path = new PriorityQueue<>(new Comparator<>(){
            @Override
            public int compare(int[] a, int[] b){
                return b[2]-a[2];
            }
        });
        path.add(new int[]{0, 0, safety[0][0]});
        mat[0][0]=2;

        int minSafety = 0;
        while(!path.isEmpty()){
            int size = path.size();
            while(size-->0){
                int[] curr = path.poll();
                int currx = curr[0];
                int curry = curr[1];
                int currSafety = curr[2];
                if(currx==m-1 && curry==n-1)return currSafety;                
                for(int[] dir:dirArr){
                    int nextx = currx+dir[0];
                    int nexty = curry+dir[1];
                    if(isValid(nextx, nexty, mat) && mat[nextx][nexty]!=2){
                        path.add(new int[]{nextx, nexty, Math.min(currSafety, safety[nextx][nexty])});
                        mat[nextx][nexty]=2;                        
                    }
                }                     
            }                
        }
        return minSafety;
    }    
    private boolean isValid(int i, int j, int[][] mat){
        return i>=0 && i<mat.length && j>=0 && j<mat[i].length;
    }
}
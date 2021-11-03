class Solution {
    
    /**
    
      1. Find the start , box and target cordinate .
      
      2. Then using Start Cordinate start BFS . Create Normal Visted set 
      
      3. There will be  3 Possibilities :
          
           3.1 You find the Target , return whateevr No of Moves you have done till now .
           3.2 You find the Box , increase the Moves by 1, distance + moves +1  .
           3.2 You dont find Box , so move On without increasing Moves 
           
           
   NOTE : Use PriotityQueue to sort Next value by Distance to get MIN diustnace         
    
    **/
    
    
    
    private static final int [][] DIRS = {{1,0},{-1,0},{0,1},{0,-1}};
    
    public int minPushBox(char[][] grid) {
        
        // STEP-1 Find the start , Box and Target Cordinate 
        
        int start [] = new int[2];
        int box [] = new int[2];
        int target[] = new int[2];
        
        int rows = grid.length;
        int cols = grid[0].length;
        boolean startFound = false; 
        boolean boxFound = false;
        boolean targetFound = false;
        boolean found =false;
        
        for( int row =0; row < rows ; row++){
            for( int col =0; col< cols ; col++){
                 char curValue = grid[row][col];
                 switch(curValue){
                     case 'S':
                       startFound=true;
                        start[0] = row;
                        start[1] = col; 
                      break;
                     case 'B' :
                        boxFound = true;
                        box[0] = row;
                        box[1] = col;  
                       break;
                     case 'T':
                        targetFound = true; 
                        target[0] = row;
                        target[1] = col;
                        break;
                 }
                if(startFound && boxFound && targetFound){
                    found = true;
                    break;
                }
            }
            if( found){
                break;
            }
        }
        
       // STEP-2 STart BFS starting from start Cordinate
        PriorityQueue<int[]> pq = new PriorityQueue<>((pq1,pq2)->new Integer(pq1[0]).compareTo(pq2[0]));
        pq.offer(new int[]{dist(box[0],box[1], target[0],target[1]) + 0,
                           0 ,
                          start[0],
                          start[1], 
                          box[0],
                          box[1]});
        
        Set<String> visited = new HashSet<>();
        while(!pq.isEmpty()){
            int size = pq.size();
            for( int i=0; i < size ; i++){
                int [] node = pq.poll();
                int dist = node[0];
                int moves = node[1];
                int row = node[2];
                int col = node[3];
                int bxX = node[4];
                int bxY = node[5];
                
                // if box equals to target return 
                if(bxX == target[0] && bxY== target[1]){
                    return moves;
                }
                String key = row + "-" + col +"-"+ bxX +"-"+ bxY;
                if(visited.contains(key)){
                    continue;
                }
                visited.add(key);
                // EXplore 
                for(int dir []: DIRS){
                    int nRow = row + dir[0];
                    int nCol = col + dir[1];
                    if(!isValid(nRow,nCol, rows, cols, grid)){
                        continue;
                    }
                    // if its equal to Box 
                    if(bxX == nRow &&  bxY == nCol) {
                        int nBxX = nRow + dir[0];
                        int nBxY = nCol + dir[1];
                        if(!isValid(nBxX,nBxY, rows, cols, grid)){
                            continue;
                        }
                      pq.offer( new int[]{dist(nBxX,nBxY,target[0],target[1]) + moves + 1 , moves +1 , nRow,nCol,nBxX,nBxY} );
                    }else {
                        // If the new cordinate not equal to Box 
                        pq.offer( new int[]{dist,moves,nRow,nCol,bxX, bxY} );
                    }
                }
            }
        }
        return -1;
        
    }
    
    private boolean isValid(int row , int col , int rows , int cols, char grid[][]){
        if(row < 0 || row > rows-1 || col < 0 || col > cols-1 || grid [row][col] == '#'){
            return false;
        }
        return true;
    }
    
    private int dist(int x, int y, int tx, int ty){
        return Math.abs(x-tx)+Math.abs(y-ty);
    }
}
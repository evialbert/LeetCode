class Solution {
    
    int x, y;
    int pos = 0;
    
    public int[][] spiralMatrixIII(int R, int C, int r0, int c0) {
        
        int dir = 0; // 0 - right, 1 - down, 2 - left, 3 - up
        int[][] rst = new int[R*C][2];
        rst[pos++] = new int[]{r0, c0};
            
        int n = 0;
        int step = 1; // observe that each step will take twice -> 1-1-2-2-3-3-...
        
        x=r0; 
        y=c0;
        
        while(pos<R*C){ // stop until all cell visited
            f(R, C, dir, step, rst);
            dir = (dir+1)%4; // change dir
            if(++n%2==0) step++; // increase step
        }

        return rst;
    }
    
   void f(int r, int c, int dir, int step, int[][] rst){
       for(int i=0; i<step; i++){
           if(dir==0) y++;
           else if(dir==1) x++;
           else if(dir==2) y--;
           else if(dir==3) x--;
           if(x>=0 && x<r && y>=0 && y<c) rst[pos++]=new int[]{x, y}; // only put valid position to result
       }
   }
    
}
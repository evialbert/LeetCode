class Solution {
    public boolean checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
      int xn = Math.max(x1,Math.min(x2,x_center));
    int yn = Math.max(y1,Math.min(y2,y_center));
    
    return Math.sqrt((xn-x_center)*(xn-x_center)+(yn-y_center)*(yn-y_center)) <= radius;
    
} 
    }

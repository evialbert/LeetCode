class Solution {
    public static double func(double mid, int[][] squares) {
        double area = 0;
        for (int[] sq : squares) {
            double y = sq[1];
            double l = sq[2];
              if (mid >= y + l) continue; 

            if (mid <= y) { 
                area += l * l;
            } else if (mid-y <l) { 
                area += (y + l - mid) * l;
            }
        }
      
        return area;
    }
    
    public static double binary_search(double low, double high, double target, int[][] squares) {
        for (int i = 0; i < 100; i++) {
            double mid = (low + high) / 2.0;
            double area = func(mid, squares);
            if (area > target) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return high;
    }
  
    public double separateSquares(int[][] squares) {
        double ta = 0;
        double min_y = Double.MAX_VALUE;
        double max_y = -Double.MAX_VALUE;
        for (int[] square : squares) {
            double l = square[2];
            ta += l * l;
        }
          for (int[] square : squares) {
            double l = square[2];
            double y = square[1];
            min_y = Math.min(min_y, y);
            max_y = Math.max(max_y, y + l);
        }
  
        double ha = ta / 2.0;
        return binary_search(min_y, max_y, ha, squares);
    }
}
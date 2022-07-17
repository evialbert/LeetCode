class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int ans = -1;
        int dis=-1, min=Integer.MAX_VALUE;
        for (int i=0; i<points.length; i++) {
            if (x == points[i][0] || y == points[i][1]) {
                dis = Math.abs(x - points[i][0]) + Math.abs(y-points[i][1]);
                if (min > dis) {
                    min = dis;
                    ans = i;
                }
            }
        }
        
        return ans;
    }
    
    class Pair {
        int a, b;
        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }
}
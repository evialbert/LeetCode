class Solution {
    public int[] countPoints(int[][] points, int[][] queries) {
        int [] output = new int [queries.length];
        
        for (int i = 0; i < queries.length; i ++) {
            int xc = queries[i][0], yc = queries[i][1], r = queries[i][2];
            
            for (int j = 0; j < points.length; j ++) {
                int x = points[j][0], y = points[j][1];
                int d2 = (x - xc) * (x - xc) + (y - yc) * (y - yc) ;
                if (d2 <= r * r) {
                    output[i] ++;
                }
            }
        }
        return output;
    }
}
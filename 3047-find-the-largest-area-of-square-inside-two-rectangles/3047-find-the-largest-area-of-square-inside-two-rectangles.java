class Solution {
    public long largestSquareArea(int[][] bottomLeft, int[][] topRight) {
        long res = 0;
        for (int i = 0; i < bottomLeft.length; i++) {

            for (int j = i + 1; j < topRight.length; j++) {

                long area = computeArea(bottomLeft[i][0], bottomLeft[i][1], topRight[i][0], topRight[i][1],
                        bottomLeft[j][0], bottomLeft[j][1], topRight[j][0], topRight[j][1]);
                res = Math.max(res, area);
            }
        }
        return res;
    }

    public static long computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        if (ax2 < bx1 || bx2 < ax1)
            return 0;
        if (ay2 < by1 || by2 < ay1)
            return 0; 
        long right = Math.min(ax2, bx2);
        long left = Math.max(ax1, bx1);
        long top = Math.min(by2, ay2);
        long bottom = Math.max(by1, ay1);
        if ((right - left) > 0 && (top - bottom) > 0) {
            long min = Math.min((right - left), (top - bottom));
            return min * min;
        }
        return 0;
    }
}
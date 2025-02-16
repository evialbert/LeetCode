class Solution {
    private static double area(int[][] squares, double y) {

        // Compute only one side of area and return it 
        double area = 0;
        for (int[] s : squares) {
            int x = s[0], yb = s[1], l = s[2];
            int t = yb + l;
            if (y >= t) {
                continue;
            } else if (y <= yb) {
                area += (double)l * l;
            } else {
                area += (double)(t - y) * l;
            }
        }
        return area;
    }

    public double separateSquares(int[][] squares) {
        int min = Integer.MAX_VALUE;
        int max = 0;
        for (int i = 0; i < squares.length; i++) {
            min = Math.min(min, squares[i][1]);
            max = Math.max(max, squares[i][1] + squares[i][2]);
        }

        double low = min, high = max;
        double area = 0;
        for (int[] s : squares) {
            area += (double)s[2] * s[2];
        }
        area /= 2.0;

        while (low + 1e-6 < high) {
            double mid = (low + high) / 2.0;
            if (area(squares, mid) > area) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return Math.round(low * 1e5) / 1e5;
    }
}
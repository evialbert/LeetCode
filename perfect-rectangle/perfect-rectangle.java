class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        if (rectangles == null || rectangles.length == 0 || rectangles[0].length == 0) {
            return false;
        }
		// Build special treeset whose compare function returns 0 if intersect.
        Set<int[]> set = new TreeSet<>((int[] a, int[] b) -> {
            if (a[3] <= b[1]) {
                return -1;
            } else if (a[1] >= b[3]) {
                return 1;
            } else if (a[2] <= b[0]) {
                return -1;
            } else if (a[0] >= b[2]) {
                return 1;
            } else return 0;
        });
        
        int area = 0;
        int up = Integer.MIN_VALUE;
        int down = Integer.MAX_VALUE;
        int left = Integer.MAX_VALUE;
        int right = Integer.MIN_VALUE;
        
        for (int[] rect : rectangles) {
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            up = Math.max(up, rect[3]);
            right = Math.max(right, rect[2]);
            down = Math.min(down, rect[1]);
            left = Math.min(left, rect[0]);
            if (!set.add(rect)) {
                return false;
            }
        }
        if (!(((up - down) * (right - left)) == area)) return false;
        return true;
    }
}
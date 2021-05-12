class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        int a1 = distSquare(p1, p2), b1 = distSquare(p3, p4);
        int a2 = distSquare(p1, p3), b2 = distSquare(p2, p4);
        int a3 = distSquare(p1, p4), b3 = distSquare(p2, p3);
        if(a1 == 0 || a2 == 0 || a3 == 0 || a1 != b1 || a2 != b2 || a3 != b3)
            return false;
        return a1 == a2 || a1 == a3 || a2 == a3;
    }
    
    public static int distSquare(int[] a, int[] b){
        int xDiff = a[0] - b[0], yDiff = a[1] - b[1];
        return xDiff * xDiff + yDiff * yDiff;
    }
    
}
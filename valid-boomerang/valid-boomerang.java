class Solution {

    public boolean isBoomerang(int[][] points) {

        int xA = points[0][0];

        int xB = points[1][0];

        int xC = points[2][0];

        int yA = points[0][1];

        int yB = points[1][1];

        int yC = points[2][1];

        if (isSame(points[0], points[1]) || isSame(points[2], points[1]) || isSame(points[0], points[2])) return false;

        if (xA == xB && xA == xC) return false;

        if (xA == xB || xA == xC || xB == xC) return true;

        double devAB = (yA - yB + 0.0) / (xA - xB);

        double devAC = (yA - yC + 0.0) / (xA - xC);

        return devAB != devAC;

    }



    boolean isSame(int[] A, int[] B){

        return A[0] == B[0] && A[1] == B[1];

    }

}


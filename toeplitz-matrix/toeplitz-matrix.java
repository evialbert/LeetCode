class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        int m = matrix.length - 1;

        int n = matrix[0].length - 1;

        for ( int i = 0; i < m; i++ ) {

            for ( int j = 0 ; j < n ; j++) {

                if ( matrix[i][j] != matrix[i+1][j+1] ){

                    return false;

                }

            }

        }

        return true;

    }

}
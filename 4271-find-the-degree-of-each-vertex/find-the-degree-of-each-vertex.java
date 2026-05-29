class Solution {
    public int[] findDegrees(int[][] matrix) {
        int[] result = new int[matrix.length];
        for(int i=0; i<matrix.length; i++)
        {
            for(int j=0; j<matrix.length; j++)
            {
                result[j] += matrix[i][j];
            }
        }
        return result;
    }
}
class Solution {
   public long maxMatrixSum(int[][] matrix) {
        int count = 0, min = Integer.MAX_VALUE;
        long sum = 0;
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if(matrix[i][j] < 0){
                    count++;
                }
                min = Math.min(min, Math.abs(matrix[i][j]));
                sum+=Math.abs(matrix[i][j]);
            }
        }
        if(count%2 == 0){
            return sum;
        }else{
            return sum - 2*min;
        }
    }
}
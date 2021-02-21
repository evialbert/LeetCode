class Solution {
    public int[][] transpose(int[][] A) {
        int hei = A.length;
        int col = A[0].length;
        if(col == hei && col == 1)
            return A;
            
        int[][] res = new int[col][hei];
        for(int j = 0; j<col; j++){
            for(int i = 0; i<hei; i++){
                res[j][i] = A[i][j];       
            }
        }
        return res;
    }
}
class NumMatrix {

    private int[][] matrix;
    
    public NumMatrix(int[][] matrix) {
        this.matrix = matrix;    
        initialize();
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = matrix[row2][col2];
        
        if(row1 > 0) {
            sum -= matrix[row1 - 1][col2];
        }
        
        if(col1 > 0) {
            sum = sum - matrix[row2][col1 - 1];
        }
        
        if(row1 > 0 && col1 > 0) {
            sum += matrix[row1 - 1][col1 - 1];
        }
        return sum;
    }
    
    private void initialize() {
        
        if(matrix == null || matrix.length == 0) {
            return;
        }
        
        for(int i = 1; i < matrix[0].length; i++) {
            matrix[0][i] += matrix[0][i - 1];
        }
        
        for(int i = 1; i < matrix.length; i++) {
            matrix[i][0] += matrix[i - 1][0];
        }
        
        for(int i = 1; i < matrix.length; i++) {
            for(int j = 1; j < matrix[0].length; j++) {
                matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j] 
                    + matrix[i][j] - matrix[i - 1][j - 1];
            }
        }
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
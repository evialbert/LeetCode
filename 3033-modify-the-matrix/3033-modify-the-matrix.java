class Solution {
    public int[][] modifiedMatrix(int[][] matrix) {
        // Initialize a new array with the same dimensions as the input matrix
        int[][] arr = new int[matrix.length][matrix[0].length];
        
        // Iterate through each column of the matrix
        for (int i = 0; i < matrix[0].length; i++) {
            // Initialize max to -1
            int max = -1;
            
            // Find the maximum non-negative value in the current column
            for (int j = 0; j < matrix.length; j++) {
                // Skip if the element is -1
                if (matrix[j][i] == -1) {
                    continue;
                }
                // Assign the element's value to the corresponding position in arr
                arr[j][i] = matrix[j][i];
                // Update max if necessary
                if (max < arr[j][i]) {
                    max = arr[j][i];
                }
            }
            
            // Replace all occurrences of -1 in the current column with the maximum value
            for (int j = 0; j < matrix.length; j++) {
                if (matrix[j][i] == -1) {
                    arr[j][i] = max;
                }
            }
        }
        
        // Return the modified array
        return arr;
    }
}
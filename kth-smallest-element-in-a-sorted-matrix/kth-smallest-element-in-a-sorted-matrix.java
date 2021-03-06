//Binary Search
 class Solution {
	  public int kthSmallest(int[][] matrix, int k) {
        int n = matrix.length;
        int left = matrix[0][0];
        int right = matrix[n-1][n-1];
        
        int result = 0;
        while (left <= right){
            int mid = left + (right - left) / 2;
            int count = countSmallerThanMid(mid, matrix);
            if (count < k)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
    
    // count how many elements are there lesser than the mid
    private int countSmallerThanMid(int mid, int[][] matrix){
        int n  = matrix.length;
        int j = n-1;
        int count = 0;
        
        for (int i=0;i<n;i++){
            while (j >= 0 && matrix[i][j] > mid)
                j--;
            count += j+1;
        }
        return count;
    }
    
}
class Solution {
	
	public static int updateAndCheck(int[][] nums, int[] row) {
		int[][] check = new int[nums.length][nums[0].length];
        int ans=0;
		for(int i=0; i<nums.length; i++) {
            boolean check1 = true;
			for(int j=0; j<nums[0].length; j++) {
				//Flipping all the indexes of zeros 
				if(row[j]==0) {
					if(nums[i][j]==0) {
						check[i][j]=1;
					}else {
						check[i][j]=0;
					}
				}else {
					check[i][j] = nums[i][j];
				}

                if(j>0 && check[i][j]!=check[i][j-1]){
                    check1 = false;
                    break;
                }
			}
            if(check1){
                ans+=1;
            }
		}
        return ans;
	}

	public static int maxEqualRowsAfterFlips(int[][] matrix) {
        int ans=0;
        for(int i=0; i<matrix.length; i++) {        	
        	int check=updateAndCheck(matrix, matrix[i]);
        	if(check>ans) {
        		ans = check;
        	}
        }
		return ans;
    }
}
class Solution {

	private int r, c;
	private int[][]dp;
	public int maxSideLength(int[][] mat, int threshold) {

		r = mat.length;
		c = mat[0].length;

		dp = new int[r+1][c+1];

		for(int i = 1; i <= r; i++){
			for(int j = 1; j <= c; j++){
				 dp[i][j] = mat[i-1][j-1] + dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1];
			}
		}

		int left = 1;
		int right = Math.min(r,c);

		while(left < right){

			int mid = right - (right - left)/2;

			if(helper(mid, threshold)){
				left = mid;
			}
			else
				right = mid - 1;
		}

		if(helper(left, threshold)){
			return left;
		}
		return 0;
	}

	private boolean helper(int k, int threshold){

		for(int i = k; i <= r; i++){
			for(int j = k; j <= c; j++){

				int sum = dp[i][j] -dp[i][j-k]-dp[i-k][j] + dp[i-k][j-k];

				if(sum <= threshold){
					return true;
				}
			} 
		}
	  return false;
	}
}
class Solution {
	public int bestTeamScore(int[] scores, int[] ages) {
		// store the data in one array
        
		int maxScore = 0;
		int[][] dp = new int[scores.length][2];
		for (int i = 0; i < scores.length; i++) {
			dp[i][0] = scores[i];
			dp[i][1] = ages[i];
			maxScore = Math.max(maxScore, scores[i]);
		}
		// sort by age but if age is eqaul then sort by scores 
        Arrays.sort(dp, (a, b) -> (a[1] == b[1]) ? (a[0] - b[0]) : (a[1] - b[1]));
		
        // create a dp array to store to total maximum score till ith postion 
        int dp1[] = new int[scores.length];
		int max = 0;

        // from each postion go to previous postion , we are checking basically all the player who has same age or less age , if score of the indiviual is less than
        // the corrent player ,  add the total maximum score till the postion with current player score , you do same with each previous player and get the maxumum and store in dp[i] 
		for (int i = 0; i < scores.length; i++) {
			int score = dp[i][0];
			dp1[i] = dp[i][0];
			for (int j = i - 1; j >= 0; j--) {
				if (dp[i][0] >= dp[j][0]) {
					dp1[i] = Math.max(dp1[i], score + dp1[j]);
				}
			}
			max = Math.max(max, dp1[i]);
		}
		return max;
	}
}

class Solution {
    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        // arrangement
        int k = factory.length;
        int n = robot.size();
        Collections.sort(robot);
        Arrays.sort(factory, new Comparator<>(){
            public int compare(int[] one, int[] two) {
                return one[0] - two[0];
            }
        });
        //
        long[][] dp = new long[k][n];
        // initial state: handle i-1 (i==0)
        for (int i = 0; i < n; i++) {
            int limit = factory[0][1];
            if (i+1 <= limit) {
                if (i == 0) {
                    dp[0][i] = (long)Math.abs(factory[0][0] - robot.get(i));
                } else {
                    dp[0][i] = dp[0][i-1] + (long)Math.abs(factory[0][0] - robot.get(i));
                }
            } else {
                dp[0][i] = Long.MAX_VALUE/2; // change to -1 in the future
            }
        }

        // dp
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < n; j++) {
                // dp[i-1][j - m]
                dp[i][j] = dp[i-1][j];
                long cost = 0l;
                for (int m = 1; m <= factory[i][1] && j-m+1 >= 0; m++) {
                    cost += (long)Math.abs(factory[i][0] - robot.get(j-m+1));
                    if (j-m+1 == 0) {
                        dp[i][j] = Math.min(dp[i][j], cost);
                    } else {
                        dp[i][j] = Math.min(dp[i][j], dp[i-1][j-m] + cost);
                    }
                }
            }
        }
        return dp[k-1][n-1];
    }
}
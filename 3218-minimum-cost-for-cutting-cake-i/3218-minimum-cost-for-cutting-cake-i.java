class Solution {
    Integer[][][][] dp = new Integer[21][21][21][21];
    public int minimumCost(int m, int n, int[] hc, int[] vc) {
        return helper(0, 0, n, m, vc, hc);
    }

    private int helper(int x1, int y1, int x2, int y2, int[] hc, int[] vc) {
        // base case
        if ((x1 + 1 == x2) && (y1 + 1 == y2)) {
            return 0;
        }
        // already visit
        if (dp[x1][y1][x2][y2] != null) return dp[x1][y1][x2][y2];

        int curr = Integer.MAX_VALUE;
    
        for (int cutX = x1; cutX < x2 - 1; cutX++) {
            int left = helper(x1,  y1, cutX + 1, y2, hc, vc);
            int right = helper(cutX + 1,y1, x2, y2, hc, vc);
            curr = Math.min(curr, left + right + hc[cutX]);    
        }

        for (int cutY = y1; cutY < y2 - 1; cutY++) {
            int up = helper(x1, y1, x2, cutY + 1, hc, vc);
            int down = helper(x1, cutY + 1, x2, y2, hc, vc);
            curr = Math.min(curr, up + down + vc[cutY]);   
        }
        
        return dp[x1][y1][x2][y2] = curr;

    }
}
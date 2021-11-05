class Solution {
    public final int MOD = (int)1e9+7;
    public int numWays(int steps, int arrLen) {
        int[][] memo = new int[steps/2+2][steps+1];
        for(int i = 0; i <= steps/2; i++) {
            Arrays.fill(memo[i], -1);
        }
        return numWays(steps, 0, arrLen, memo);
    }
    
    private int numWays(int steps, int pos, int n, int[][] memo) {
        if (pos >= n || pos < 0) return 0;
        if (steps == 0 && pos == 0) return 1;
        if (steps == 0 && pos != 0) return 0;
        if (memo[pos][steps] >= 0) return memo[pos][steps];
        
        int left  = numWays(steps-1, pos-1, n, memo);
        int right = numWays(steps-1, pos+1, n, memo);
        int stay  = numWays(steps-1, pos, n, memo);
        
        return memo[pos][steps] = ((left%MOD + right)%MOD + stay)%MOD;
    }
}
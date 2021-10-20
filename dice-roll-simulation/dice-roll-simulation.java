class Solution {
    private static final long MOD = 1000000007;
    
    public int dieSimulator(int n, int[] rollMax) {
        long[][] all = new long[6][15 + 1];
        long[] countsBySide = new long[6];
        long total = 0, newTotal;
        int max;

        for(int j = 0; j < all.length; j++) {
            all[j][0 + 1] = 1;
            countsBySide[j] = 1;
            
            total = 6;
        }

        for(int i = 1; i < n; i++) {
            newTotal = total;
            
            for(int j = 0; j < all.length; j++) {
                all[j][0] = (total - countsBySide[j]) % MOD;

                max = rollMax[j];

                newTotal = (newTotal - all[j][max] + all[j][0]);
                
                countsBySide[j] = (total - all[j][max]) % MOD;

                for(int k = max; k >= 1; k--) {
                    all[j][k] = all[j][k - 1];
                }

                // all[j][0] = 0;
            }
            
            total = newTotal;
        }
        
        return (int) (total % MOD);
    }
}
class Solution {
    public int numMusicPlaylists(int N, int L, int K) {
        int mod = 1000000007;
        long[] dp = new long[N + 1];
        dp[0] = 1;
        
        for (int i = 0; i < L; i++) {
            long[] cur = new long[N+1];
            
            for (int j = 1; j <= N; j++){
                cur[j] = (dp[j - 1] * (N - (j - 1))) % mod; 
                
                if (j > K){
                    cur[j] = (cur[j] + (dp[j] * (j - K)) % mod) % mod;
                }
            }
            
            dp = cur;
        }
        return (int) dp[N];
    }
}
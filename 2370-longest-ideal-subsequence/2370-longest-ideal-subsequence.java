class Solution {

    static int dp[][];
    static int helper(String s, int K, int idx, char prev) {
        if (idx == s.length())
            return 0;

        if(dp[idx][prev]!=-1) return dp[idx][prev];

        char ch = s.charAt(idx);
        int pick = 0;

        // Include the current character
        if (Math.abs(prev-ch)<=K || prev=='#') {
            pick = 1 + helper(s, K, idx + 1, ch);
        }

        // Exclude the current character
        int notPick = helper(s, K, idx + 1, prev);

        return dp[idx][prev] = Math.max(pick,notPick);
    }
    
    public int longestIdealString(String s, int K) {
        int n = s.length();
        dp = new int[100005][150];
        for(var a : dp) Arrays.fill(a,-1);
        return helper(s, K, 0,'#');
    }
}
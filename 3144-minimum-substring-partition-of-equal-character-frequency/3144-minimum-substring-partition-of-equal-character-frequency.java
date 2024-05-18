class Solution {
    
    private boolean hasEqualFreq(int[] counts) {
        Integer freq = null;
        boolean hasEqualFreq = true;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] > 0) {
                if (freq == null) freq = counts[i];
                else if (freq != counts[i]) {
                    hasEqualFreq = false;
                    break;
                }
            }
        }
        return hasEqualFreq;
    }
    
    private int findMinPartitions(int startIdx, String s, Integer[] dp) {
        if (startIdx >= s.length()) {
            return 0;
        }
        
        if (dp[startIdx] != null) {
            return dp[startIdx];
        }
        
        int[] counts = new int[26];
        int minFreq = Integer.MAX_VALUE;
        for (int i = startIdx; i < s.length(); ++i) {
            counts[s.charAt(i) - 'a']++;
            if (hasEqualFreq(counts)) {
                minFreq = Math.min(minFreq, 1 + findMinPartitions(i + 1, s, dp));
            }
        }
        return dp[startIdx] = minFreq;
    }
    
    public int minimumSubstringsInPartition(String s) {
        Integer[] dp = new Integer[s.length()];
        return findMinPartitions(0, s, dp);
    }
}
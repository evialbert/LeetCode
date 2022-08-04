class Solution {
    int mod = (int) Math.pow(10,9)+7;
    public int numberOfUniqueGoodSubsequences(String binary) {
        if(!binary.contains("1")){
            return 1;
        }
        int len = binary.length();
        int[] last = new int[2];
        Arrays.fill(last, -1);
        long[] dp = new long[len];
        int start = binary.indexOf('1') + 1;
        dp[start - 1] = 1;
        for (int i = start; i < binary.length(); i++) {
            int ch = Character.getNumericValue(binary.charAt(i));
            dp[i] = 2 * dp[i - 1];
            dp[i]%=mod;
            if (last[ch] - 1 >= 0) {
                dp[i] -= dp[last[ch] - 1];
                dp[i]+=mod;
                dp[i]%=mod;
            }
            last[ch] = i;
        }
        return (int) dp[len - 1] + (binary.contains("0") ? 1 : 0);
    }
}
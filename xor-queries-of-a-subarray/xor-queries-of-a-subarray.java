class Solution {
    public int[] xorQueries(int[] arr, int[][] queries) {
        int[] dp = new int[arr.length];
        dp[0] = arr[0];
        for (int i = 1; i < arr.length; i++) {
            dp[i] = dp[i-1] ^ arr[i];
        }
        
        // populate result array
        int[] res = new int[queries.length];
        int index = 0;
        for (int[] query : queries) {
            int end = dp[query[1]];
            if (query[0] != 0) {
                end ^= dp[query[0] -1];
            }
            
            res[index++] = end;
        }
        return res;
    }
}
class Solution {
    public int minExtraChar(String s, String[] dictionary) {
        final Set<String> dict = new HashSet<>();
        final int[] dp = new int[s.length() + 1];

        for(String word : dictionary)
            dict.add(word);

        for(int i = 1; i < dp.length; ++i) {
            dp[i] = dp[i - 1] + 1;

            for(int j = i - 1; j >= 0; --j) {
                String sub = s.substring(j, i);

                if(dict.contains(sub))
                    dp[i] = Math.min(dp[i], dp[j]);
            }
        }

        return dp[dp.length - 1];
    }
}
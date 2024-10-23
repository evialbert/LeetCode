class Solution {
    public int numberOfSubstrings(String s, int k) {
        int n = s.length();
        int count = 0;

        for (int left = 0; left < n; left++) {
            int[] freq = new int[26];

            for (int right = left; right < n; right++) {
                freq[s.charAt(right) - 'a']++;

                if (freq[s.charAt(right) - 'a'] >= k) {
                    count += n - right;
                    break;
                }
            }
        }
        return count;
    }
}
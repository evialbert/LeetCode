class Solution {
    public int takeCharacters(String s, int k) {
        // edge cases
        int n = s.length();
        int[] count = new int[3];
        for (int i = 0; i < n; i++) {
            count[s.charAt(i) - 'a']++;
        }
        if (count[0] < k || count[1] < k || count[2] < k) {
            return -1;
        }
        // normal cases
        int result = n;
        int left = 0;
        for (int right = 0; right < n; right++) {
            char ch = s.charAt(right);
            count[ch - 'a']--;
            while (count[ch - 'a'] < k) {
                count[s.charAt(left++) - 'a']++;
            }
            result = Math.min(result, n - (right - left + 1));
        }
        return result;
    }
}

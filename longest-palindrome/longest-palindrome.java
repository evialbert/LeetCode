class Solution {
    public int longestPalindrome(String s) {   
        int[] lowercase = new int[26];
        int[] uppercase = new int[26];
        int res = 0;
        for (char c : s.toCharArray()) {
            if (c >= 97) lowercase[c-'a']++;
            else uppercase[c-'A']++;
        }
        for (int i = 0; i < 26; i++){
            res += (lowercase[i] / 2) * 2;
            res += (uppercase[i] / 2) * 2;
        }
        return res == s.length() ? res : res+1;
    }
}
class Solution {
    public int findSubstringInWraproundString(String p) {
        int[] count = new int[26];
        int n = p.length(), res = 0, len = 0;
        for (int i = 0; i < n; i++) {
            if (i >= 1 && Math.floorMod(p.charAt(i) - p.charAt(i - 1), 26) == 1) {
                len++;
            }
            else {
                len = 1;
            }
            count[p.charAt(i) - 'a'] = Math.max(count[p.charAt(i) - 'a'], len);
        }
        for (int item: count) {
            res += item;
        }
        return res;
    }
}
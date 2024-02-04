class Solution {
    public String minWindow(String s, String t) {
        int[] need = new int[128];
        int[] seen = new int[128];
        for (char c : t.toCharArray()) need[c]++;
        String ans = "";
        for (int i = 0, j = 0, found = 0; j < s.length(); j++) {
            char c = s.charAt(j);
            if (++seen[c] <= need[c]) found++;
            for (; found == t.length(); i++) {
                if (j - i + 1 < ans.length() || ans.isEmpty()) ans = s.substring(i, j + 1);
                c = s.charAt(i);
                if (--seen[c] < need[c]) found--;
            }
        }
        return ans;
    }
}
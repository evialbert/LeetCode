class Solution {
    public boolean buddyStrings(String A, String B) {
        if (A == null || B == null || A.length() != B.length()) return false;
        char[] s1 = A.toCharArray();
        char[] s2 = B.toCharArray();
        if (A.equals(B)) {
            int[] dict = new int[26];
            for (char ch: s1) {
                dict[ch-'a']++;
                if (dict[ch-'a'] >= 2) return true;
            }
            return false;
        }
        
        List<Integer> diffIndex = new ArrayList<>();
        for (int i = 0; i < s1.length; i++) {
            if (s1[i] != s2[i]) diffIndex.add(i);
        }
        if (diffIndex.size() != 2) return false;
        int i = diffIndex.get(0), j = diffIndex.get(1);
        if (A.charAt(i) == B.charAt(j) && A.charAt(j) == B.charAt(i)) return true;
        return false;
    }
}
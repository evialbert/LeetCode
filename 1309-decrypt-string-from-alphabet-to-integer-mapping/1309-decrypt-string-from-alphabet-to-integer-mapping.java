class Solution {
    public String freqAlphabets(String s) {
        StringBuilder SB = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (((i+2) < s.length()) && (s.charAt(i+2) == '#')) {
                SB.append(Character.toString(96 + Integer.parseInt(s.substring(i, i+2))));
                i += 2;
            }
            else {
                SB.append(Character.toString(96 + Integer.parseInt(s.substring(i, i+1))));
            }
        }
        return SB.toString();
    }
}
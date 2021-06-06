class Solution {
    public boolean canTransform(String start, String end) {
        if (start.length() != end.length()) return false;
        int rnum = 0, lnum = 0;
        for (int i = 0; i < start.length(); i++) {
            if (start.charAt(i) == 'R') {
                rnum++;
            }
            if (start.charAt(i) == 'L') {
                lnum--;
            }
            if (rnum > 0 && lnum != 0) return false;
            if (end.charAt(i) == 'R') {
                rnum--;
            }
            if (end.charAt(i) == 'L') {
                lnum++;
            }
            if (rnum < 0 || lnum < 0) return false;
            if (rnum > 0 && lnum > 0) return false;
        }
        return rnum == 0 && lnum == 0;
    }
}
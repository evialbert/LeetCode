class Solution {
    public boolean hasMatch(String s, String p) {
        int index = p.indexOf("*");
        String sub1 = p.substring(0, index);
        String sub2 = p.substring(index + 1);

        int start = s.indexOf(sub1);
        if (start == -1) return false;

        int end = s.indexOf(sub2, start + sub1.length());
        if (end == -1) return false;

        return true;
    }
}
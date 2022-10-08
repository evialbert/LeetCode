class Solution {
    public boolean checkString(String s) {
        return s.lastIndexOf('a') < (s.indexOf('b') != -1 ? s.indexOf('b') : Integer.MAX_VALUE);
    }
}
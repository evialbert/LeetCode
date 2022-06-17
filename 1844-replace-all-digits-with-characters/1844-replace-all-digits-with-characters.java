class Solution {
    public String replaceDigits(String s) {
        return this.sol(s);
    }
    public String sol(String s) {
        char[] c = s.toCharArray();
       for(int i = 1;i<s.length();i = i + 2) {
           int u = (c[i] - '0');
           c[i] = (char)(c[i - 1] + u);
       }
       s = new String(c);
       return s;
    }
}
class Solution {
    public int scoreOfString(String s) {
        int n = s.length();
        int sc = 0;  // sc = score

        for(int i=0; i<n-1; i++) {
            sc += Math.abs((s.charAt(i)-'a') - (s.charAt(i+1)-'a'));
        }

        return sc;
    }
}
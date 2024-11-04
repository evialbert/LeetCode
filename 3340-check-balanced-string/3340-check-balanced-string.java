class Solution {
    public boolean isBalanced(String num) {
    int s1=0, s2 = 0, n = num.length();
    for(int i=0; i<n; i++) {
        char ch = num.charAt(i);
        if(i%2 == 0) {
            s2 += (ch-'0');
        } else {
            s1 += (ch-'0');
        }
    }
    return s1==s2;
}
}
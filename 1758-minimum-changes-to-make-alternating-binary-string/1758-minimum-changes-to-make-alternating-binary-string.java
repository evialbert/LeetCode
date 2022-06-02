class Solution {
    public int minOperations(String s) {
        String zeroStart = constructAlternating(s.length(), true);
        String oneStart = constructAlternating(s.length(), false);
        return Math.min(getDiff(s, zeroStart), getDiff(s, oneStart));
    }
    
    private int getDiff(String s, String alter) {
        int count = 0;
        
        for (int i = 0; i < s.length(); i++)
            count = s.charAt(i) == alter.charAt(i) ? count + 1 : count;
        
        return count;
    }
    
    private String constructAlternating(int len, boolean startZero) {
        char ch = startZero ? '0' : '1';
        StringBuilder ans = new StringBuilder();
        
        for (int i = 0; i < len; i++) {
            ans.append(ch);
            ch = ch == '0' ? '1' : '0';
        }
        
        return ans.toString();
    }
}
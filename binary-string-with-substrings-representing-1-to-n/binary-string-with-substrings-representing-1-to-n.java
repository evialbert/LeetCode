class Solution {
    public boolean queryString(String s, int n) {
        for(int i = 1 ; i <= n ; i++) {
            String binary = Integer.toBinaryString(i);
            if(!s.contains(binary)) return false; 
        }
        return true;
    }
}
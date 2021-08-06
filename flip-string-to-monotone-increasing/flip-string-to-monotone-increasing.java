class Solution {
    public int minFlipsMonoIncr(String S) {
        
        int min = 0, i = 0, ones = 0;
        
        while (i < S.length()) {
            
            if (S.charAt(i) == '1') {
                
                ++ones;
            } else if (ones > 0) {
                
                ++min;
                --ones;
            }
            
            ++i;
        }
        
         return min;
    }
}
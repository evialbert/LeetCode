class Solution {
    public boolean checkRecord(String s) {
        int countA = 0;
        int countL = 0;
        for(char c : s.toCharArray()) {
            if(c == 'A') {
                countA++;
            }
            
            if(c == 'L') {
                countL++;
            } else {
                countL = 0;
            }
            
            if(countA>1 || countL>2) {
               return false;
            }
        }
        return true;
    }
}

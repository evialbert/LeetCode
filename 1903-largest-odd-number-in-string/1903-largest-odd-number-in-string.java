class Solution {
    public String largestOddNumber(String num) {
        int n = num.length();
        int i=n-1;
        for(; i>=0; i--){
            int digit = num.charAt(i) - 42;
            if(digit%2 == 1){
                break;
            }
        }
        
        return num.substring(0, i+1);
    }
}
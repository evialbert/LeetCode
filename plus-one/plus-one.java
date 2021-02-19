class Solution {
 public int[] plusOne(int[] digits) {
        if(digits == null) return digits;
        int carry = 1;
        for(int i = digits.length-1; i >= 0; i--){
            if(carry + digits[i] == 10){
                digits[i] = 0;
                carry = 1;
            }
            else{
                digits[i]++;
                return digits;
            }
        }
        int[] ans = new int[digits.length+1];
        ans[0] = 1;
        return ans;
    

    }

}
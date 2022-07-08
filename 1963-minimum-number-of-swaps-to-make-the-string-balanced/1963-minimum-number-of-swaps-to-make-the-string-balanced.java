class Solution {
   public int minSwaps(String s) {
        int bal = 0, left = 0, right = 0;
        for(char c : s.toCharArray()){
            if(c == '['){
                left++;
            }else{
                right++;
            }
            bal = Math.max(bal, right - left);
        }
        return (bal + 1) / 2;
    }
}


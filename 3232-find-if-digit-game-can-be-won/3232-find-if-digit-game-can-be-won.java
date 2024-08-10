class Solution {
    public boolean canAliceWin(int[] nums) {
        int sum1 = 0,num1 = 0,sum2= 0, num2 = 0;
        for(int i : nums){
            String s = Integer.toString(i);
            if(s.length() == 1){
                sum1+=i;
            }else{
                num1+=i;
            }
        }
        for(int i : nums){
            String s = Integer.toString(i);
            if(s.length() == 2){
                sum2+=i;
            }else{
                num2+=i;
            }
        }
        if(sum1 > num1 || sum2 > num2){
            return true;
        }
        return false;
    }
}
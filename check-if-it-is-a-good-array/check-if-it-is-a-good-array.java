class Solution {
    public boolean isGoodArray(int[] nums) {
        int result = nums[0];
        for(int i=1; i<nums.length; i++){
          result = findGCD(nums[i], result);
        }
        if(result == 1){
            return true;
        }
        else{
            return false;
        }
    }
    public static int findGCD(int a, int b){
    if(b == 0)
      return a;
    return findGCD(b, a%b);
    }
}
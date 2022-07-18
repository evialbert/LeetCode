class Solution {
    public int arraySign(int[] nums) {
        int product = 1;
        for(int numbers : nums){
            if(numbers == 0){
                return 0;
            }
            if(numbers < 0){
                product *= -1;
            }
            else{
                product *= 1;
            }
        }
        return product;
    }
}
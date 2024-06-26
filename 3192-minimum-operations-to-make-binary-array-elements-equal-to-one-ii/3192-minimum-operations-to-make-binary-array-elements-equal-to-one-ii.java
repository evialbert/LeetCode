class Solution {
    public int minOperations(int[] nums) {
        int check = 0;
        int count = 0;
        for(int i =0;i<nums.length;i++){
            if(nums[i]==check){
                if(check==0){
                    check=1;
                }
                else{
                    check=0;
                }
                count++;
            }
        }
        return count;
    }
}
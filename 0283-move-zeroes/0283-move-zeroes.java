class Solution {
    public void moveZeroes(int[] nums) {
        int c=0,j=0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }else{
                c++;
            }
        }
        for(int i=nums.length-c;i<nums.length;i++){
            nums[i]=0;
        }
    }
}
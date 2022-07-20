class Solution {
    public void moveZeroes(int[] nums) {
        int k=0,z=0,len=nums.length;
        for(int i=0;i<len;i++){
            if(nums[i]!=0){
                nums[k]=nums[i];
                k++;
            }else{
                z++;
            }
        }
        while(z!=0){
            nums[len-z]=0;
            z--;
        }
    }
}
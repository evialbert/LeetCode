class Solution {
    private static int getBitValue(int num){
        int count=0;
        while(num>0){
            count+=num&1;
            num>>=1;
        }
        return count;
}
    public boolean canSortArray(int[] nums) {
        int i=0;
        int j=1;
        while(j<nums.length){
            //check if adjacent bits are same 
          if(getBitValue(nums[i])==getBitValue(nums[j])){
              //if same then check if curr val is >next val
              if(nums[i]>nums[j]){
               int temp=nums[i];
               nums[i]=nums[j];
               nums[j]=temp;
                  i=0;
                  j=1;
              }else{
                  //if is already sorted dont swap and inc by 1 
                  i++;
                  j++;
              }
          }else{
              i++;
              j++;
          }
        
        }
        for(int k=0;k<nums.length;k++){
            if(k<nums.length-1&&nums[k]>nums[k+1]){
                return false;
            }
}
        return true;
    }
}
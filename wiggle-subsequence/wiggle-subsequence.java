class Solution {
  public int wiggleMaxLength(int[] nums) {
        
        if(nums.length==0)
            return 0;
        
        int inc =1;// initialize increment to 1
        int dec =1;// initialize decrement to 1
        for(int i=1;i<nums.length;i++){
            if(nums[i]>nums[i-1])// if incrementing sequence at i 
                inc= dec+1;
            else if(nums[i-1]>nums[i])// if decrementing sequence at i
                dec = inc+1;
        }
        return Math.max(inc,dec);//Longest wiggle seqeunce
        
    }
}
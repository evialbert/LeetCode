class Solution {
    public long minOperationsToMakeMedianK(int[] nums, int k) 
    {
     Arrays.sort(nums);
     int mid=nums.length/2;
     long ans=0;
     if(nums[mid]>k)
     {
         while(mid>=0 && nums[mid]>k)
         {
             ans+=(nums[mid]-k);
             mid--;
         }
     }
        else if(nums[mid]<k)
        {
            while(mid<nums.length && nums[mid]<k)
            {
                ans+=(k-nums[mid]);
            mid++;
            }
        }
        return ans;
        
        
    }
}
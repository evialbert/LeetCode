class Solution {
    public long countSubarrays(int[] nums, int minK, int maxK) {
        int minKPos=-1;
        int maxKPos=-1;
        int culpritIdx=-1;
        long ans=0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]<minK||nums[i]>maxK)culpritIdx=i;


            if(nums[i]==minK)minKPos=i;

            if(nums[i]==maxK)maxKPos=i;

            int smaller=Math.min(minKPos,maxKPos);

            int temp=smaller-culpritIdx;

            ans+=(temp<=0)?0:temp;
        }
        return ans;
        
    }
}
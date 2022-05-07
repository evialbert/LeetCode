class Solution {
    public int maximumUniqueSubarray(int[] nums) {
       Set<Integer>set=new HashSet<>();
        int sum=0,ans=0;
        for(int i=0,j=0;i<nums.length;i++){
               while(set.contains(nums[i])){
                   set.remove(nums[j]);
                   sum-=nums[j++];
               }
            sum+=nums[i];
            set.add(nums[i]);
            ans=Math.max(ans,sum);
        }
        return ans;
    }
}
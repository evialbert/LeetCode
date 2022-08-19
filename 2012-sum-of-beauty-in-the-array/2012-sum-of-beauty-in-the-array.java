class Solution {
    public int sumOfBeauties(int[] nums) {
        int ans=0;
        int n= nums.length;
        int min[]=new int[n];
        int max[]=new int[n];
        max[0] = nums[0];
        for(int i=1;i<n;i++)max[i] = Math.max(max[i-1], nums[i]);
        min[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            min[i] = Math.min(nums[i],min[i+1]);
        }
        for(int i=1;i<n-1;i++){
            if(nums[i]>nums[i-1] && nums[i]<nums[i+1]){
                if(nums[i]>max[i-1] && nums[i]<min[i+1])ans+=2;
                else ans++;
            }
            else continue;
        }
        return ans;
    }
}
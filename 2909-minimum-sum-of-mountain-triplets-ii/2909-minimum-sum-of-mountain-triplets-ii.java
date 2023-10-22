class Solution {
    public int minimumSum(int[] nums) {
        int n = nums.length;
        int[] prefixMin = new int[n];
        prefixMin[0] = nums[0];
        for(int i=1;i<n;i++){
            prefixMin[i] = Math.min(nums[i],prefixMin[i-1]);
        }
        
        int[] suffixMin = new int[n];
        suffixMin[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffixMin[i] = Math.min(nums[i],suffixMin[i+1]);
        }
        int ans = Integer.MAX_VALUE;
        boolean found = false;
        for(int i=0;i<n;i++){
            if(prefixMin[i]<nums[i] && suffixMin[i]<nums[i]){
                found = true;
                ans = Math.min(prefixMin[i]+nums[i]+suffixMin[i],ans);
            }
        }
        if(found){
           return ans ;
        }else{
            return -1;
        }
        
    }
}
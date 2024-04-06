class Solution {
    public long countAlternatingSubarrays(int[] nums) {
        int l=0;
        int r=0;
        long ans = 0;
        int p = -1;
        while(r<nums.length){
            if(nums[r]==p){
                l = r;
            }
            ans += r-l+1;
            p =nums[r];
            
            r++;
        }
        return ans;
    }
}
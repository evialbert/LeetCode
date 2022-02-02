class Solution {
    public int longestSubarray(int[] nums) {
        int ans = 0;
        int l = nums.length;
        boolean present = false;
        for(int i=0; i<l; i++) {
            if(nums[i] == 1) {
                present = true;
                continue;
            }
            int c = 0;
            for(int j=i-1; j>=0; j--) {
                if(nums[j] == 0)
                    break;
                c++;
            }
            for(int j=i+1; j<l; j++) {
                if(nums[j] == 0)
                    break;
                c++;
            }
            ans = Math.max(ans, c);
        }
        if(ans == 0 && l == 1)
            return 0;
        if(!present)
            return 0;
        if(ans == 0)
            return l-1;
        return ans;
    }
}
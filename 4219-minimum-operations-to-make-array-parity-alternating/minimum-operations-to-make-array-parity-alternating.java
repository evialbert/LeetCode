class Solution {
    public int[] makeParityAlternating(int[] nums) {
        int n = nums.length;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for(int i=0; i<n; i++) {
            max = Math.max(max, nums[i]);
            min = Math.min(min, nums[i]);
        }
        //case-1 :o-e-o
        int ans1 = 0;
        int max1=Integer.MIN_VALUE;
        int min1=Integer.MAX_VALUE;
        for(int i=0; i<n; i++) {
            if(((i%2 == 0) && Math.abs(nums[i]%2) == 1) || ((i%2 == 1) && nums[i]%2 == 0)) {
                 max1 = Math.max(max1, nums[i]);
                min1 = Math.min(min1, nums[i]); continue;
            }
            if(nums[i] == min) {
                max1 = Math.max(max1, nums[i]+1);
                min1 = Math.min(min1, nums[i]+1);
            }
            else if(nums[i] == max) {
                 max1 = Math.max(max1, nums[i]-1);
                min1 = Math.min(min1, nums[i]-1);
            }
            ans1++;
        }


         //case-2 :e-o-e
        int ans2 = 0;
        int max2=Integer.MIN_VALUE;
        int min2=Integer.MAX_VALUE;
        for(int i=0; i<n; i++) {
                       if(((i%2 == 0) && nums[i]%2 == 0) || ((i%2 == 1) && Math.abs(nums[i]%2) == 1)) {
                 max2 = Math.max(max2, nums[i]);
                min2 = Math.min(min2, nums[i]); continue;
            }
            if(nums[i] == min) {
                max2 = Math.max(max2, nums[i]+1);
                min2 = Math.min(min2, nums[i]+1);
            }
            else if(nums[i] == max) {
                 max2 = Math.max(max2, nums[i]-1);
                min2 = Math.min(min2, nums[i]-1);
            }
            ans2++;
        }
          int[] ans = new int[2];
        if(ans1 == ans2) {
            ans[0] = ans1;
            int mn = Math.min(max1-min1, max2-min2);
            ans[1] = mn;
        }
        else if(ans1 < ans2) {
            ans[0] = ans1;
            ans[1] = max1-min1;
        }
        else{
            ans[0] = ans2;
            ans[1] = max2-min2;
        }
        // ans[0] = min1;
        // ans[1] = max1;
        // ans[2] = min2;
        // ans[3] = max2;
        // ans[0] = ans1;
        // ans[1] = ans2;
        return ans;
        
    }
}
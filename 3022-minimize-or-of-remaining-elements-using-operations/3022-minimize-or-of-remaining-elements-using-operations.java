class Solution {
    int solve(int target, boolean[] take, int[] nums){
        int ans = 0;
        int i = 0;
        int n = nums.length;
        while(i < n){
            if(!take[i]){
                i+=1;
                continue;
            }
            int st = i;
            int all = nums[i];
            while(i < n && take[i] && (all & target) != 0){
                all&=nums[i];
                i+=1;
            }
            if( (all & target) == 0){
                ans += ( i - st - 1);
            }else{
                ans += (i - st);
            }
        }
        return ans;
    }
    public int minOrAfterOperations(int[] nums, int k) {
        int n = nums.length;
        int ans = 0;
        int res = 0;
        for(int bit = 29; bit >= 0; bit--){
            int mask = res | (1 << bit);
            boolean[] take = new boolean[n];
            Arrays.fill(take, false);
            for(int i = 0; i < n; i++){
                if( (nums[i] & mask) == 0) continue;
                take[i] = true;
            }
            int op = solve(mask, take, nums);
            if(op <= k)
                res = mask;
            else
                ans = ans | (1 << bit);
        }
        return ans;
        
    }
}
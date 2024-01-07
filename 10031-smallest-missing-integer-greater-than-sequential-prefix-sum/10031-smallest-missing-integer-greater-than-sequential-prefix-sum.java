class Solution {
    public int missingInteger(int[] nums) {
        int sum = nums[0];
        for(int i=1; i<nums.length; i++) {
            if(nums[i-1]+1 == nums[i]) {
                sum += nums[i];
            }
            else {
                break;
            }
        }
        
        HashSet<Integer> set = new HashSet<>();
        
        for(int i=0; i<nums.length; i++) {
            set.add(nums[i]);
        }
        
        int ans = sum;
        while(true) {
            if(!set.contains(sum)) {
                ans = sum;
                break;
            }
            else {
                sum += 1;
            }
        }
        
        return ans;
        
    }
}
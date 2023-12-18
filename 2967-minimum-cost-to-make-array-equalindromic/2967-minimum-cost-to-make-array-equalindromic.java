class Solution {
    public long minimumCost(int[] nums) {
        Arrays.sort(nums);
        
        int median = nums[nums.length/2];
        
        int median_left = median;
        int median_right = median;

        // find closest palidrome to left and right of medium
        
        while(!palindrome(median_left)){
            median_left--;
        }
        while(!palindrome(median_right)){
            median_right++;
        }

        // add to cost and return min_cost
        
        long cost1 = 0, cost2 = 0;
        for(int i=0;i<nums.length;i++){
            cost1 += Math.abs(nums[i] - median_left);
            cost2 += Math.abs(nums[i] - median_right);
        }
        return Math.min(cost1, cost2);
        
    }
    boolean palindrome(long n){
        long orig = n;
        long num = 0;
        while(orig > 0){
            num = num*10 + orig%10;
            orig /= 10;
        }
        return num == n;
    }
}
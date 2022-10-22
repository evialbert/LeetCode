class Solution {
   public long minimumDifference(int[] nums) {
        PriorityQueue<Integer> max = new PriorityQueue<Integer>(Collections.reverseOrder());
        PriorityQueue<Integer> min = new PriorityQueue();
        int n = nums.length/3;
        long []leftSum = new long[n+1];
        long sum = 0;
        for(int i=0;i<2*n;i++){
            sum += nums[i];
            max.add(nums[i]);
            if(i >= n-1){
                if(i >= n){
                    sum -= max.poll();
                }
                leftSum[i-n+1] = sum;
            }
        }
        long []rightSum = new long[n+1];
        sum = 0;
        for(int i=3*n-1;i>=n; i--){
            sum += nums[i];
            min.add(nums[i]);
            if(i <= 2*n){
                if(i < 2*n){
                    sum -= min.poll();
                }
                rightSum[2*n - i] = sum;
            }
        }
        long ans = Long.MAX_VALUE;
        for(int i=0;i<=n;i++){
            ans = Math.min(ans, leftSum[i] - rightSum[n-i]);
        }
        return ans;
    }
}
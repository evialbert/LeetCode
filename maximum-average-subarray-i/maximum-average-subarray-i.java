public class Solution {
    public double findMaxAverage(int[] nums, int k) {
        if(nums.length == 1) return nums[0];
        int max = 0;
        for(int i=0;i<k;i++){
            max += nums[i];
        }
        int tmp =max;
        for(int i=k;i<nums.length;i++){
            tmp = tmp + nums[i] - nums[i-k];
            if(tmp>max){
                max = tmp;
            }

        }
        return (double)max/k;
        
    }
}
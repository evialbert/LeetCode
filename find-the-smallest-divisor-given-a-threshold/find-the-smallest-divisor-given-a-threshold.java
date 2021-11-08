class Solution {
   public int smallestDivisor(int[] nums, int threshold) {
        
        int max = Integer.MIN_VALUE;
        
        for(int num : nums){
            if(num > max){
                max = num;
            }
        }
        
        int left = 1;
        int right = max;
        
        while(left < right){
            int mid = (left + right)/2;
            int sum = 0;
            for(int num : nums){
                sum += Math.ceil(num/(double)mid);
            }
            
            if(sum > threshold){
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return left;
        
    }
}
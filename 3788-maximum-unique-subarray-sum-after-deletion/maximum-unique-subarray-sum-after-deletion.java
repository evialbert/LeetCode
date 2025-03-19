class Solution {
    public int maxSum(int[] nums) {
        HashSet<Integer> closet = new HashSet<>();

        int max=Integer.MIN_VALUE;

        int maxSum=Integer.MIN_VALUE, runningSum=0;

        boolean neg=false, zero=false;

        for(int num:nums){
            if(num<0){
                neg=true;
            }

            if(num ==0){
                zero=true;
            }
            if(num>0){
                if(!closet.contains(num)){
                    closet.add(num);
                    runningSum+=num;
                    maxSum = Math.max(runningSum, maxSum);
                }
                
            }
            max = Math.max(max, num);
        }

        if(maxSum == Integer.MIN_VALUE){
            if(zero){
                return 0;
            }
            
            if(neg){
                return max;
            }
        }

        return maxSum;
    }
}
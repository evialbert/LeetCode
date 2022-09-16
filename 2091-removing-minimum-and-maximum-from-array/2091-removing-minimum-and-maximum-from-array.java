class Solution {
    public int minimumDeletions(int[] nums) {
        int[] temp = new int[nums.length];
        for(int i  = 0; i < nums.length; i++){
            temp[i] = nums[i];
        }
        Arrays.sort(temp);
        int min = temp[0];
        int max = temp[nums.length-1];
        int minI = 0;
        int maxI = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] == min)minI = i;
            if(nums[i] == max)maxI = i;
        }
        
        int front = Math.max(nums.length-minI,nums.length-maxI);//3,7=7
        int back = Math.max(minI+1,maxI+1);//6,2=6
        int both = Math.min(nums.length-minI,minI+1)+Math.min(nums.length-maxI,maxI+1);//3+2
        return Math.min(Math.min(front,back),both);
    }
}
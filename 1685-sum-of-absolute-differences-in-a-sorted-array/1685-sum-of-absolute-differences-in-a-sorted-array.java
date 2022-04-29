class Solution {
    public int[] getSumAbsoluteDifferences(int[] nums) {
        int[] postSum = new int[nums.length];
        for(int i=nums.length-1; i>=0;i--){
            if(i == nums.length-1){
                postSum[i] = nums[i];
            }
            else{
                postSum[i] = postSum[i+1] + nums[i];
            }
        }
        int[] res = new int[nums.length];
        int pSum = 0;
        for(int i=0; i<res.length;i++){
            int lNum = 0, rNum = 0;
            if(i!=0){
                lNum = i * nums[i] - pSum;
            }
            if(i != res.length -1){
                rNum = postSum[i+1] - (res.length-1-i) * nums[i];
            }
            pSum += nums[i];
            res[i] = lNum + rNum;
        }
        return res;
    }
}
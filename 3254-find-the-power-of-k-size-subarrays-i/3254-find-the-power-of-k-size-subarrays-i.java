class Solution {
    public int[] resultsArray(int[] nums, int k) {
        if(k==1) return nums;
        int [] ans= new int[nums.length-k+1];
        if(nums.length==1){
            ans[0]=nums[0];
            return ans;
        }
        Arrays.fill(ans,-1);
        int i=0;
        int j=1;
        while(j<nums.length){
            while(j<nums.length && nums[j]==nums[j-1]+1){
                if(j-i+1>=k){
                    ans[j-k+1]=nums[j];
                }
                j++;
            }
            i=j;
            j=i+1;
        }
        return ans;
    }
}
class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int l=0;
        boolean first=true;
        for(int i=1;i<nums.length;i++){
            if(nums[i]==0)
                l++;
            else{
                if(l<k && !first)
                    return false;
                l=0;
            }
            first=false;
        }
        return true;
    }
}
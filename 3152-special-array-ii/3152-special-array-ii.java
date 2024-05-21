class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] q) {
        int[] spc=new int[nums.length];
        spc[0] = 0;
        int pp = nums[0]%2;
        int sm = spc[0];
        for(int i=1;i<nums.length;i++){
            int cp = nums[i]%2;
            if(cp==pp){
                spc[i] = i;
                sm = i;
            }
            else{
                spc[i] = sm;
            }
            pp=cp;
        }
        boolean[] ans=new boolean[q.length];
        for(int i=0;i<q.length;i++){
            if(spc[q[i][0]]==spc[q[i][1]]) ans[i]=true;
            else ans[i] = false;
        }
        return ans;
    }
}
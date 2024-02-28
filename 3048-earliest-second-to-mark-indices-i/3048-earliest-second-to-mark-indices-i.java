class Solution {
    public int earliestSecondToMarkIndices(int[] nums, int[] changeIndices) {
        int a=earliestsec(nums,changeIndices);
        if(a==-1)return -1;
        return a+1;
    }
    private static int earliestsec(int[]nums,int[]changeidx){
        int ans=-1;
        int l=0;
        int u=changeidx.length-1;
        while(l<=u){
            int m=l+(u-l)/2;
            if(possible(m,nums,changeidx)){
                ans=m;
                u=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
    private static boolean possible(int m, int[] nums, int[] changeidx) {
        int op=0;
        int mark=0;
        Integer[]last=new Integer[nums.length];
        for(int id=0;id<=m;id++){
            last[changeidx[id]-1]=id;
        }
        for(int i=0;i<=m;i++){
            int id=changeidx[i]-1;
            if(last[id]!=null&&last[id]==i){
                if(op>=nums[id]){
                    mark++;
                    op-=nums[id];
                }
                else{
                    return false;
                }
            }
            else{
                op++;
            }
        }
        return mark==nums.length;
    }
}
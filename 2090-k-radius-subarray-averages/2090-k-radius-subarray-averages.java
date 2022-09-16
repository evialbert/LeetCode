class Solution {
    public int[] getAverages(int[] nums, int k) {
        int n=nums.length;
        int rs[]=new int[n];
        int low=0;
        int high=2*k;
        long sum=0;
        long prev=0;

        if(k==0){
            return nums;
        }
        if(2*k+1>nums.length){
            Arrays.fill(rs, -1);
            return rs;
        }

        for(int i=0;i<n&&i<=high;i++){
            sum+=nums[i];
            rs[i]=-1;
        }
        if(k<n){
            rs[k]= (int) (sum/(2*k+1));
            prev=sum;
        }

        for(int i=k+1;i+k<n;i++){
            prev=prev-nums[low++]+nums[++high];
            rs[i]= (int) (prev/(2*k+1));
        }
        for(int i=n-k;n-k>=0&&i<n;i++){
            rs[i]=-1;
        }
        return rs;
    }
}
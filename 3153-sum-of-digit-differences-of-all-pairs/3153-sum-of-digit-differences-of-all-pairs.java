class Solution {
    public long sumDigitDifferences(int[] nums) {
        int n=Integer.toString(nums[0]).length();
        long ans=0;
        int[][] count=new int[n][10];
        for(int x:nums){
            int i=n-1;
            while(i>=0){
                count[i--][x%10]++;
                x/=10;
            }
        }
        for(int i=0;i<count.length;i++){
          for(int j=0;j<count[0].length;j++){
            if(count[i][j]==0){
                continue;
            }
            int k=j+1;
            long count1=0;
            int num=count[i][j];
            while(k<count[0].length){
              count1+=num*count[i][k];
              k++;
            }
            ans+=count1;
          }
        }
        return ans;
    }
}
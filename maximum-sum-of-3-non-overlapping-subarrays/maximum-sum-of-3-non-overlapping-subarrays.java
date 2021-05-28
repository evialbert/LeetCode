class Solution {
    public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int n = nums.length;
        int[] l = new int[n];
        int[] lindex = new int[n];
        int[] r = new int[n];
        int[] rindex = new int[n];
        l[0]=nums[0];
        int max=Integer.MIN_VALUE;
        int[] org = new int[n];
        for(int i=1;i<k;i++){
            l[i]=nums[i]+l[i-1];
            org[i]=l[i];
        }
        for(int i=k;i<n;i++){
            l[i]=nums[i]+l[i-1]-nums[i-k];
            org[i]=l[i];
        }
        for(int i=k;i<n;i++){
            if(l[i]>l[i-1]){
                lindex[i]=i-k+1;
            }else{
                l[i]=l[i-1];
                lindex[i]=lindex[i-1];
            }
        }
        
        
        
        r[n-1]=nums[n-1];
        for(int i=n-2;i>=n-k;i--){
            r[i]=nums[i]+r[i+1];
        }
        for(int i=n-k-1;i>=0;i--){
            r[i]=r[i+1]+nums[i]-nums[i+k];
        }
        rindex[n-k]=n-k;
        for(int i=n-k-1;i>=0;i--){
            if(r[i]>=r[i+1]){
                rindex[i]=i;
            }else{
                r[i]=r[i+1];
                rindex[i]=rindex[i+1];
            }
        }
        
        
        max = Integer.MIN_VALUE;
    
        int[] ans = new int[3];
        
        
        for(int i=2*k-1;i<n-k;i++){
            int sum = org[i]+r[i+1]+l[i-k];
            if(sum>max){
                max=sum;
                ans[0]=lindex[i-k];
                ans[1]=i-k+1;
                ans[2]=rindex[i+1];
            }
        
        }
        return ans;
    }
}
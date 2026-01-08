class Solution {
    public int longestSubarray(int[] nums) {
        int n=nums.length;
        if(nums.length==1){
            return 1;
        }
        int left[]=new int[n];
        int right[]=new int[n]; 
        left[0]=1;
        for(int i=1;i<n;i++){
           if(nums[i]>=nums[i-1]){
            left[i]=left[i-1]+1;
           }else{
            left[i]=1;
           }
        }
        right[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=nums[i+1]){
                right[i]=right[i+1]+1;
            }else{
                right[i]=1;

            }
        }
        int max=0;
        
        for(int i=0;i<n;i++){
            if(i==0){
                max=Math.max(max,1+right[i+1]);

            }else if(i==n-1){
                max=Math.max(max,1+left[i-1]);
            }else{
                int l=left[i-1];
                int r=right[i+1];
                int prev=nums[i-1];
                int next=nums[i+1];
                if(next>=prev){
                    max=Math.max(max,1+l+r);
                }else{
                    max=Math.max(max,Math.max(l+1,r+1));
                   
                }
            }
        }
        max=Math.min(max,n);
        return max;
  
    }
}
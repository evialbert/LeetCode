class Solution {
   public boolean check(int [] nums,int mid,int maxOperations){
    int n=nums.length;
    for(int i=0;i<n;i++){
        maxOperations-=(nums[i]/mid);
        if(nums[i]%mid==0){
            maxOperations++;
        }
    }
    return maxOperations>=0;
}
public int minimumSize(int[] nums, int maxOperations) {
    int start=1;
    int end=Integer.MAX_VALUE;
    int ans=0;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(check(nums,mid,maxOperations)){
            ans=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}
}
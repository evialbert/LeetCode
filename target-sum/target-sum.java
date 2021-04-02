//csum-> currentSum
//idx-> index
class Solution {
    public int findTargetSumWays(int[] arr, int sum) {
        return helper(arr,sum,0);
    }
    public int helper(int arr[],int csum,int idx){
      
      if(idx==arr.length){
        if(csum==0){
          return 1;
        }
        else{
          return 0;
        }
      }
      
      //first option
      int fo=helper(arr,csum-arr[idx],idx+1);
      
      //second option
      int so=helper(arr,csum+arr[idx],idx+1);
      return fo+so;
    }
}
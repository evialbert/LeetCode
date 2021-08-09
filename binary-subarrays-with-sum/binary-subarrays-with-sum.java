class Solution {
    public int numSubarraysWithSum(int[] arr, int goal) {
        return helper(arr,goal) - helper(arr,goal - 1);
    }
   public int helper(int arr[],int goal){
        if(goal < 0 ) return 0;
        int i = 0;
        int j = 0;
        int n = arr.length;
        int cs = 0;
        int res = 0;
        while(j < n){
          cs = cs + arr[j];
          
          if(cs > goal){
              while(i < n && cs > goal){
                cs = cs - arr[i]; 
                i++;
              }
          }
            res = res + (j - i + 1);
          
          j++;
        }
      return res;
   }
}
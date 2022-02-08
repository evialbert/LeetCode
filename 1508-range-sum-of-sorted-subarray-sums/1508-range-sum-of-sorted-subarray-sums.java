class Solution {
    public int rangeSum(int[] nums, int n, int left, int right) {
        
        int mod = (int)1e9+7;
            
        int[] arr= new int[n*(n+1)/2];
        int k= 0;
        
        for (int i= 0; i< n; i++) {
            int acc= 0;
            for (int j=i; j<n; j++) {
                acc += nums[j];
                arr[k] = acc;
                k++;
            }
        }
        
        Arrays.sort(arr);
        int res= 0;
        
        for (int i= left-1; i< right; i++) {
            res = (res+ arr[i])% mod;
        }
        
        return res;
        
    }
}
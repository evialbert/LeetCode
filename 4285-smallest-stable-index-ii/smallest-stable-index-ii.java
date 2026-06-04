class Solution {
    public int firstStableIndex(int[] nums, int k) {
        int n = nums.length;
        int[] arr = new int[n];
        int min = nums[n-1];
        for(int i = n-1; i>=0; i--){
            min = Math.min(min, nums[i]);
            arr[i] = min;
        }
        int max = arr[0];
        for(int i = 0; i<n; i++){
            max = Math.max(max, nums[i]);
            int stab = max-arr[i];
            if(stab<=k) return i;
        }
        return -1;
    }
}
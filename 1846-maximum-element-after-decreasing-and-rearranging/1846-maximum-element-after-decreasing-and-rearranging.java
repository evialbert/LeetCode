class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;
        arr[0] = 1;
        for(int i=0;i<n-1;i++) {
            int diff = arr[i+1]-arr[i];
            arr[i+1] = diff == 0 || diff == 1 ? arr[i+1] : arr[i] + 1;
        }
        return arr[n-1];
    }
}
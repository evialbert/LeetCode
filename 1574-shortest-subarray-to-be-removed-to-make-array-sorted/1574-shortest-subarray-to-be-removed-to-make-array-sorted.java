class Solution {
    public int binarySearch(int[] arr, int start, int val){
        int res = arr.length;
        int l = start;
        int r = arr.length-1;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            if( arr[mid] >= val){
                res = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        
        return res;
    }
    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length;
        int i = 0;
        int j = n-1;

        while(i+1 < n && arr[i] <= arr[i+1])
            i++;
        while(j-1 >= i && arr[j] >= arr[j-1])
            j--;
        
        if( i == j)
            return 0;
        int max = Math.min(n-i-1, j);
        
        for(int k = 0; k <= i; k++){
            int ind = binarySearch(arr, j, arr[k]);
            max = Math.min(max, ind-k-1);
        }
        return max;
    }
}
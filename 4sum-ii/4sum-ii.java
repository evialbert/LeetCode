class Solution {
    public int fourSumCount(int[] a, int[] b, int[] c, int[] d) {
        int[] sum1 = new int[a.length * a.length];
        int[] sum2 = new int[a.length * a.length];

        int counter = 0;
        for(int i = 0; i < a.length; i++){
            for(int j = 0; j < a.length; j++){
                sum1[counter] = (a[i] + b[j]);
                sum2[counter] = (c[i] + d[j]);
                counter++;
            }
        }

        Arrays.sort(sum1);
        Arrays.sort(sum2);

        int count = 0;
        for(int x : sum1){
            int l = leftMost(sum2, 0, sum2.length-1, -x);
            int r = rightMost(sum2, 0, sum2.length-1, -x);
            
            if(l != -1 && r != -1) {
                count+=(r-l+1);
            }
        }
        return count;
    }

    public int leftMost(int[] arr, int start, int end, int x) {
        if (start > end) {
            return -1;
        }
        int mid = start + (end - start) / 2;

        if (arr[mid] == x && (mid == 0 || arr[mid - 1] != x)) {
            return mid;
        }
        if (arr[mid] >= x) {
            return (leftMost(arr, start, mid - 1, x));
        }
        return leftMost(arr, mid + 1, end, x);
    }

    public int rightMost(int[] arr, int low, int high, int x){
        if(low > high) return -1;

        int mid = low + (high - low)/2;

        if(arr[mid] == x && (mid == arr.length-1 || arr[mid+1] != x)){
            return mid;
        }
        if(arr[mid] > x){
            return rightMost(arr, low, mid - 1, x);
        }
        return rightMost(arr, mid + 1, high, x);
    }
}
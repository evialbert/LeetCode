class Solution {
    public int[] numberGame(int[] arr) {
        Arrays.sort(arr);
        int n = arr.length;

        for(int i=0; i<n-1; i=i+2){
            int a = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = a;
        }

        return arr;

    }
}